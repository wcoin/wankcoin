Wankcoin integration/staging tree
================================

Copyright (c) 2009-2013 Bitcoin Developers
Copyright (c) 2014-2018 Wankcoin Developers

What is Wankcoin?
----------------

Wankcoin is an experimental new digital currency that enables instant payments to
anyone, anywhere in the world. Wankcoin uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. Wankcoin is also the name of the open source
software which enables the use of this currency.

For more information, as well as an immediately useable, binary version of
the Wankcoin client software, see http://www.wankcoin.com.

License
-------

Wankcoin is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.

Wankcoin is based on Bitcoin.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test. Please be patient and help out, and
remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write unit tests for new code, and to
submit new unit tests for old code.

Unit tests for the core code are in `src/test/`. To compile and run them:

    cd src; make -f makefile.unix test

Unit tests for the GUI code are in `src/qt/test/`. To compile and run them:

    qmake BITCOIN_QT_TEST=1 -o Makefile.test bitcoin-qt.pro
    make -f Makefile.test
    ./wankcoin-qt_test

