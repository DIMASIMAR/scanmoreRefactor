class AcquisitionService {
private:
    SensorManager sensorManager;
    DeviceManager deviceManager;
    ImageProcessor imageProcessor;

public:
    bool prepareAcquisition(ExamId id);
    bool startAcquisition(ExamId id);
    bool stopAcquisition(ExamId id);
    Image getLastAcquiredImage();
    std::vector<Image> getAllAcquiredImages(ExamId id);
};
