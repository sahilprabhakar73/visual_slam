

#include <compute_features/utils.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/features2d.hpp>
#include <opencv4/opencv2/xfeatures2d.hpp>

using namespace comp_feature;





class feature_extract{
    

    protected:
        struct feature_output{
            std::vector<cv::KeyPoint> kpy_1, kpy_2;
            cv::Mat dsp_1, dsp_2;

        };

        std::shared_ptr<feature_output> results_;
        

    public:
        feature_extract() = default;
        
        virtual void compute_feature(std::shared_ptr<cv::Mat> img_1, std::shared_ptr<cv::Mat>) = 0;

         //function to draw_matches. 
};