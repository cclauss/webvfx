// Copyright (c) 2011 Hewlett-Packard Development Company, L.P. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROMIX_WEB_RENDERER_H_
#define CHROMIX_WEB_RENDERER_H_

#include <QtWebKit>
#include "chromix/mix_kit.h"

namespace Chromix
{

class WebPage;

class WebRenderer : public QObject, public MixKit
{
    Q_OBJECT

public:
    WebRenderer(QObject *parent = 0);
    void initialize(const std::string& url, int width, int height);
    void setSize(int width, int height);
    void destroy();

private:
    ~WebRenderer();

    Q_INVOKABLE void initializeInvokable(const QUrl& url, const QSize& size);
    Q_INVOKABLE void setSizeInvokable(const QSize& size);

    // Test if we are currently on the UI thread
    bool onUIThread() {
        QThread::currentThread() == QApplication::instance()->thread();
    };

    WebPage* webPage;
};

}

#endif