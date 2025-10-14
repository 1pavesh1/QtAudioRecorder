#ifndef RECORDMODEL_H
#define RECORDMODEL_H

#include <QString>
#include <QByteArray>

class RecordModel
{
private:
    QByteArray recordData;
    qint32     timeRecord;

public:

    RecordModel(const QByteArray &recordData, const qint32 &timeRecord) : recordData(recordData), timeRecord(timeRecord) {

    }

    void SetRecordData(const QByteArray &recordData) {
        this->recordData = recordData;
    }

    void SetTimeRecord(const qint32 &timeRecord) {
        this->timeRecord = timeRecord;
    }

    QByteArray GetRecordData() const {
        return recordData;
    }

    qint32 GetTimeRecord() const {
        return timeRecord;
    }
};

#endif // RECORDMODEL_H
