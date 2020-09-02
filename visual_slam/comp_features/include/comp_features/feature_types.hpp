#include <comp_features/feature_abstract.hpp>

using namespace comp_feature;

class orb_feature: protected feature_extract{

    public:

        orb_feature() = default;


        virtual void compute_feature(std::shared_ptr<cv::Mat> img_1, std::shared_ptr<cv::Mat> img_2) override{
            
            cv::Ptr<cv::FeatureDetector> detect_ = cv::ORB::create();
            cv::Ptr<cv::DescriptorExtractor> descriptors_ = cv::ORB::create();
            // create a param class that will load and  define the values for instances defined above.

            detect_->compute(*img_1, results_->kpy_1);
            detect_->compute(*img_2, results_->kpy_2);

            descriptors_->compute(*img_1, results_->kpy_1, results_->dsp_1);
            descriptors_->compute(*img_2, results_->kpy_2, results_->dsp_2);
            
        }


};




