class Exam {
protected:
    ExamId id;
    ExamType type;
    ExamStatus status;
    PatientData patientData;
    DateTime creationDate;

public:
    virtual bool validate() = 0;
    virtual void prepare() = 0;
    virtual void start() = 0;
    virtual void abort() = 0;
    virtual void complete() = 0;
};