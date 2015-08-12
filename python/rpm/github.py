#!/usr/bin/env python
import urllib2
import json
import getpass
import base64

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
            self._username, self._password = self._get_password()

    def _get_password(self):

        url = "https://api.github.com/repos/{0}/{1}/branches".format(
                self._user, self._repository
              )
        request = urllib2.Request(url)

        success = False
        count = 0
        while not success and count < 3:
            username = raw_input("This repository needs authorization, please enter your username : " if count == 0 else "Wrong username or password, please enter your username : ")
            password = getpass.getpass()
            base64_string = base64.encodestring('%s:%s' % (username, password)
                            )
            request.add_header("Authorization", "Basic %s" % base64_string)

            try:
                result = urllib2.urlopen(request)
                success = True
            except urllib2.HTTPError:
                pass

            count += 1

        if not success:
            print "Authorization failed."
            import sys
            sys.exit(1)

        return username, password

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

    def get_default_branch(self):

        pass

    def get_branches(self):
        """
            If this repository is private, please provide username
            and password.
        """

        url = "https://api.github.com/repos/{0}/{1}/branches".format(
                self.user, self.repository
              )
        request = urllib2.Request(url)

        if self._need_authorization:
            base64_string = base64.encodestring('%s:%s' % (self._username,
                                                self._password)
                            )
            request.add_header("Authorization", "Basic %s" % base64_string)

        result = urllib2.urlopen(request)
        branches = []

if __name__ == '__main__':

#    c = GithubTarballDownloader('j84255801912', 'gcoin_test')
    c = GithubTarballDownloader('OpenNetworking', 'gcoin')
