class Device {
public:
    virtual bool connect() = 0;
    virtual bool disconnect() = 0;
    virtual bool reset() = 0;
    virtual bool setExamType(ExamType type) = 0;
    virtual bool setTechnicalFactors(KiloVolts kv, MilliAmpere ma) = 0;
    virtual bool enableMRT(bool enabled) = 0;
    virtual StatusBase getStatus() = 0;
    virtual bool sendTrajectory(const Trajectory& trajectory) = 0;
};