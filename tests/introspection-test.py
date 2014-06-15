#!/usr/bin/env python

"""
This is a python script for integration test.
With libciyu correctly installed, tests here were supposed to pass
"""

import unittest
from gi.repository import Ciyu

class TestCiyu(unittest.TestCase):

    def test_ciyu_creation(self):
        entry = Ciyu.Entry(ciyu = "Python Test", frequency = 2501)
        ciyu = entry.get_property("ciyu")
        freq = entry.get_property("frequency")
        self.assertEqual(ciyu, "Python Test")
        self.assertEqual(freq, 2501)
        entry.hello()

if __name__ == '__main__':
    unittest.main()
