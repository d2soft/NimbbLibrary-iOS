typedef NS_ENUM (NSUInteger, NimbbPlayerQuality) {
    NimbbPlayerQualityLow = 1,
    NimbbPlayerQualityMedium = 2
};


typedef void (^FailDetailsBlock)(NSError *);
typedef void (^ConfigurationCompletedBlock)(void);
typedef void (^VideoSavedBlock)(NSString *);
typedef void (^VideoUploadProgressionBlock)(NSUInteger bytesWritten, long long totalBytesWritten, long long totalBytesExpectedToWrite);
typedef void (^VideoWasCanceledBlock)(void);
