#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("wankcoin:16VYmN5M2pj9Vk4aU4urWex1qppStVp1su?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("wankcoin:16VYmN5M2pj9Vk4aU4urWex1qppStVp1su?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("16VYmN5M2pj9Vk4aU4urWex1qppStVp1su"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("wankcoin:16VYmN5M2pj9Vk4aU4urWex1qppStVp1su?label=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("16VYmN5M2pj9Vk4aU4urWex1qppStVp1su"));
    QVERIFY(rv.label == QString("Wikipedia Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("wankcoin:16VYmN5M2pj9Vk4aU4urWex1qppStVp1su?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("16VYmN5M2pj9Vk4aU4urWex1qppStVp1su"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("wankcoin:16VYmN5M2pj9Vk4aU4urWex1qppStVp1su?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("16VYmN5M2pj9Vk4aU4urWex1qppStVp1su"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("wankcoin:16VYmN5M2pj9Vk4aU4urWex1qppStVp1su?amount=100&label=Wikipedia Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("16VYmN5M2pj9Vk4aU4urWex1qppStVp1su"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Wikipedia Example"));

    uri.setUrl(QString("wankcoin:16VYmN5M2pj9Vk4aU4urWex1qppStVp1su?message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("16VYmN5M2pj9Vk4aU4urWex1qppStVp1su"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("wankcoin://16VYmN5M2pj9Vk4aU4urWex1qppStVp1su?message=Wikipedia Example Address", &rv));
    QVERIFY(rv.address == QString("16VYmN5M2pj9Vk4aU4urWex1qppStVp1su"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("wankcoin:16VYmN5M2pj9Vk4aU4urWex1qppStVp1su?req-message=Wikipedia Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("wankcoin:16VYmN5M2pj9Vk4aU4urWex1qppStVp1su?amount=1,000&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("wankcoin:16VYmN5M2pj9Vk4aU4urWex1qppStVp1su?amount=1,000.0&label=Wikipedia Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
