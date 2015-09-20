#!/usr/bin/env python

import base64
import getpass
import json
import os
import urllib2

class GithubTarballDownloader(object):
    """
        1. Connect to github and get branch and commit informations.
        2. Download the tarball from the repo.
    """

    def __init__(self, user, repository):

        self._user = user
        self._repository = repository
        self._need_authorization = self._test_authorization_needed()
        if self._need_authorization:
            self._token = self._get_token()

        self._branch = self.determine_branch()
        self._commit = self.determine_commit()

    def _get_token(self):

        url = "https://api.github.com/repos/{0}/{1}/branches".format(
                self._user, self._repository
              )

        success = False
        attempts = 3
        while not success and attempts > 0: # try three times
            request = urllib2.Request(url)

            username = raw_input("This repository needs authorization," +
                                 " please enter your username : " if attempts == 3
                                 else
                                   "Wrong username or password," +
                                   "please enter your username : ")
            password = getpass.getpass()
            # this yields something like 'brk0MjU1ODAxOLMyOnswOTA3MDkwNw==\n'
            # so we need to trim '\n'
            base64_string = base64.encodestring('%s:%s' % (username, password)
                            ).replace('\n', '')
            request.add_header("Authorization", "Basic %s" % base64_string)

            try:
                result = urllib2.urlopen(request)
                success = True
            except urllib2.HTTPError:
                pass

            attempts -= 1

        if not success:
            print "Authorization failed."
            import sys
            sys.exit(1)

        return base64_string

    def _test_authorization_needed(self):

        url = "https://api.github.com/repos/{0}/{1}/branches".format(
                self._user, self._repository
              )
        request = urllib2.Request(url)
        try:
            result = urllib2.urlopen(request)
        except urllib2.HTTPError:
            return True

        return False

    def _do_request(self, url):

        request = urllib2.Request(url)

        if self._need_authorization:
            request.add_header("Authorization", "Basic %s" % self._token)

        result = urllib2.urlopen(request)
        result_json = json.loads(result.readlines()[0])

        return result_json

    def get_default_branch(self):
        """
            Get the default branch from the repository.
        """

        url = "https://api.github.com/repos/{0}/{1}".format(self._user,
                self._repository
              )
        request_json = self._do_request(url)

        return request_json['default_branch']

    def get_branches(self):
        """
            If this repository is private, please provide username
            and password.
        """

        url = "https://api.github.com/repos/{0}/{1}/branches".format(
                self._user, self._repository
              )
        result_json = self._do_request(url)

        branches = [(i['name'], i['commit']['sha']) for i in result_json]

        return branches

    def determine_branch(self):
        """
            Determine which branch.
        """

        default_branch = self.get_default_branch()
        branches = self.get_branches()

        print "\n\n\n\n\n"
        print "Branches of {}/{}".format(self._user, self._repository)
        print ("=" * 80)
        for i in branches:
            print "%25s\t%s" % (i[0], i[1])
        print ""

        answer = raw_input("choose one branch : [{}] ".format(default_branch))
        if answer not in [i[0] for i in branches]:
            answer = default_branch

        return answer

    def get_commits(self, branch):

        url = "https://api.github.com/repos/{0}/{1}/commits?sha={2}".format(
                self._user, self._repository, branch
              )

        result_json = self._do_request(url)
        commit_verbose = [str(i['sha']) for i in result_json]
        trimmed_commit_data = [(str(i['sha'][:8]),
                                i['commit']['author']['name'],
                                i['commit']['message'][:20].replace('\n', '') + "...")
                                for i in result_json]

        return commit_verbose, trimmed_commit_data

    def determine_commit(self):

        commit_verbose, trimmed_commit_data = self.get_commits(self._branch)

        print "\n\n\n\n\n"
        print "Commits of branch {}".format(self._branch)
        print ("=" * 80)
        print "%10s%25s%25s" % ("{commit}", "{author}", "{message}")
        #print "{commit}\t{author}\t{message}"
        for i in trimmed_commit_data:
            print "%10s%25s%25s" % (i[0], i[1], i[2])
        print ""

        answer = raw_input("choose one commit : [{}] ".format(
                    trimmed_commit_data[0][0])
                 )

        for i in commit_verbose:
            if i.startswith(answer):
                return i

        return commit_verbose[0] # default is the commit_verbose[0], which is the HEAD

    def download_tarball(self, path=None):

        # handle path
        # default path is the path where this script been executed
        if not path:
            path = os.path.dirname(os.path.abspath(__file__))

        if path[-1] != '/':
            path += '/'
        tarball_path = path + self._repository + "-" + self._commit + ".tar.gz"

        url = "https://github.com/{0}/{1}/archive/{2}/{1}-{2}.tar.gz".format(
                self._user, self._repository, self._commit
              )

        request = urllib2.Request(url)

        if self._need_authorization:
            request.add_header("Authorization", "Basic %s" % self._token)

        result = urllib2.urlopen(request)
        content = result.read()

        with open(tarball_path, 'w') as f:
            f.write(content)


if __name__ == '__main__':

#    c = GithubTarballDownloader('j84255801912', 'gcoin_test')
    c = GithubTarballDownloader('OpenNetworking', 'gcoin')
    c.download_tarball()
