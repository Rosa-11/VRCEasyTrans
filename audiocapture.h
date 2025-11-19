#ifndef AUDIOCAPTURE_H
#define AUDIOCAPTURE_H

#include <QObject>
#include <QAudioInput>
#include <qaudioformat.h>
#include <QAudioSource>
#include <QBuffer>
#include <QVector>
#include <QTimer>
#include "ConfigManager.h"

class AudioCapture : public QObject
{
    Q_OBJECT

private:
    // 配置
    ConfigManager& config;

    // 暂停标志
    std::atomic<bool> m_shouldStop;

    // 音频数据缓冲区
    QVector<float> m_sentenceBuffer;


public:
    AudioCapture(QObject* parent);
    ~AudioCapture();

    bool cap();
    void stop();

    QVector<float>* getBuffer();

};

#endif // AUDIOCAPTURE_H
