class PanExam : public Exam {
private:
    KiloVolts kv;
    MilliAmpere ma;
    bool mrtActive;
    AcquisitionParameters acquisitionParams;

public:
    bool validate() override;
    void prepare() override;
    void start() override;
    void abort() override;
    void complete() override;

    void setTechnicalFactors(KiloVolts kv, MilliAmpere ma);
    void setMrtActive(bool active);
};