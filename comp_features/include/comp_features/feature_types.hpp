#include <compute_features/feature_abstract.hpp>

using namespace comp_feature;

class orb_feature: protected feature_extract{

    public:

        orb_feature() = default;
        virtual void compute_feature(std::shared_ptr<cv::Mat> img_1, std::shared_ptr<cv::Mat> img_2) override;

};
