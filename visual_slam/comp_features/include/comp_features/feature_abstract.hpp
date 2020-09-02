#include <comp_features/utils.hpp>
#include <opencv4/opencv2/core.hpp>
#include <opencv4/opencv2/features2d.hpp>
#include <opencv4/opencv2/xfeatures2d.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>

using namespace comp_feature;





class feature_extract{

    struct feature_output{
            std::vector<cv::KeyPoint> kpy_1, kpy_2;
            cv::Mat dsp_1, dsp_2;

            feature_output(int keypoint_size){
                kpy_1.reserve(keypoint_size);
                kpy_2.reserve(keypoint_size);
            }

    };
    
    protected:
        std::shared_ptr<feature_output> results_; 
        

    public:
        feature_extract()   = default;
        virtual void compute_feature(std::shared_ptr<cv::Mat> img_1, std::shared_ptr<cv::Mat> img_2) = 0;
        void draw_matches(std::shared_ptr<cv::Mat> img_1, std::shared_ptr<cv::Mat> img_2);

        //function to draw_matches. 
};

feature_extract::feature_extract(){

    // results_.reset(new feature_output());
    

    
}


void feature_extract::draw_matches(std::shared_ptr<cv::Mat> img_1, std::shared_ptr<cv::Mat> img_2){

    cv::Ptr<cv::DescriptorMatcher> match_ = cv::DescriptorMatcher::create("BruteForce-Hamming");
    std::vector<cv::DMatch> matches_;
    if(results_ != nullptr){
        match_->match(results_->dsp_1, results_->dsp_2, matches_);
    }
    
    cv::Mat img_matched;
    cv::drawMatches(*img_1, results_->kpy_1, *img_2, results_->kpy_2, matches_, img_matched);
    cv::imshow("Matches image", img_matched);    

    cv::waitKey(0);

}