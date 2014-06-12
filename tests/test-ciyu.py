#!/usr/bin/env python

"""
This is a python script for integration test.
With libciyu correctly installed, tests here were supposed to pass
"""
print "hello"

import unittest
from gi.repository import Ciyu

class TestCiyu(unittest.TestCase):

    def test_ciyu_creation(self):
        ciyu = Ciyu.Entry(ciyu = "Testing", frequency = 1)
        # TODO: do some test here

if __name__ == '__main__':
    unittest.main()
