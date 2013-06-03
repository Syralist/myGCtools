#ifndef LETTERNUMBERCONVERTER_H
#define LETTERNUMBERCONVERTER_H

#include <QObject>
#include <QList>
#include <QDebug>

class LetterNumberConverter : public QObject
{
    Q_OBJECT
public:
    explicit LetterNumberConverter(QObject *parent = 0);
    bool IsValid(void);

signals:
    void UpdatedLetters(QString newString);
    void UpdatedNumbers(QString newString);
    void UpdatedStatistics(QList<int> &newStatistics);

public slots:
    void setInput(int Input);
    void setDirection(int Direction);
    void setOffset(int Offset);
    void setLetters(QString Letters);
    void setNumbers(QString Numbers);

private:
    int CrossSum(int Number);

    QString m_sLetters;
    QString m_sNumbers;
    QList<int> m_lNumbers;
    QList<int> m_lStatistics;
    int m_iInput;		//0: Letters to Numbers, 1: Numbers to Letters
    int m_iDirection;	//0: A=1, 1: Z=1
    int m_iOffset;		//Offset for Conversion
    bool m_bIsValid;
};

#endif // LETTERNUMBERCONVERTER_H
