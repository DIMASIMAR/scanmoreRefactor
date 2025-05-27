class ImageProcessingService {
private:
    FilterManager filterManager;
    ReconstrutionEngine reconstructionEngine;

public:
    Image processRawImage(Image rawImage, ProcessingParameters params);
    Image reconstructPanoramicImage(std::vector<Image> frameImages);
    Image applyFilters(Image image, std::vector<FilterType> filters);
    bool saveImage(Image image, std::string path);
};