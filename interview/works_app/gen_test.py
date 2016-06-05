import random

def select_edges(n):

    edges = []
    def gen_edges(k):
        for i in xrange(1, k):
            for j in xrange(i + 1, k + 1):
                edges.append((i, j))
    gen_edges(n)
    random.shuffle(edges)
    edges = edges[:n]
    for i in xrange(n - 1):
        print edges[i][0], edges[i][1]

def gen_queries(m, n):

    # one operation of setting a city festive out of {prob} queries.
    prob = 4
    for i in xrange(m):
        result = random.randint(0, prob - 1)
        if result % 5 == 0:
            op = 1
        else:
            op = 2
        node = random.randint(1, n)
        print op, node

def main():

    n = random.randint(2, 10 ** 3)
    m = random.randint(1, 10 ** 3)
    print n, m
    select_edges(n)
    gen_queries(m, n)


if __name__ == '__main__':

    main()
