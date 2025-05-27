class Image {
private:
    ImageId id;
    ExamId examId;
    DateTime acquisitionTime;
    ImageSize dimensions;
    std::vector<uint16_t> pixelData;
    ImageMetadata metadata;

public:
    // Metodi per manipolare l'immagine
};