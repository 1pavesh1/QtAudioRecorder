#ifndef RECORDMODEL_H
#define RECORDMODEL_H

#include <QString>
#include <QByteArray>

class RecordModel
{
private:
    QByteArray recordData;
    qint64     timeRecord;
public:
    void SetRecordData(const QByteArray &recordData) {
        this->recordData = recordData;
    }

    void SetTimeRecord(const qint64 &timeRecord) {
        this->timeRecord = timeRecord;
    }

    QByteArray GetRecordData() const {
        return recordData;
    }

    qint64 GetTimeRecord() const {
        return timeRecord;
    }
};

#endif // RECORDMODEL_H
