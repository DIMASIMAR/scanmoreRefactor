class ImageFile {
public:
    ImageFile(std::string name, ImageFormat format, const RawImage& data)
        : name(std::move(name)), format(format), imageData(data) {
    }

    std::string getName() const { return name; }
    ImageFormat getFormat() const { return format; }
    const RawImage& getImageData() const { return imageData; }

private:
    std::string name;
    ImageFormat format;
    RawImage imageData;
};