class Sensor {
public:
    virtual bool connect() = 0;
    virtual bool disconnect() = 0;
    virtual bool startAcquisition(const AcquisitionParameters& params) = 0;
    virtual bool stopAcquisition() = 0;
    virtual SensorStatus getStatus() = 0;
};