class ExamService {
private:
    DeviceRepository deviceRepo;
    SensorRepository sensorRepo;
    ExamRepository examRepo;

public:
    ExamId createExam(ExamType type, PatientData patient);
    bool configureExam(ExamId id, ExamConfiguration config);
    bool startExam(ExamId id);
    bool abortExam(ExamId id);
    bool isExamComplete(ExamId id);
    ExamResult getExamResult(ExamId id);
};