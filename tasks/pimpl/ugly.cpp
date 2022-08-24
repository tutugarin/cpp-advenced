#include <ugly.h>
#include <bad.h>

struct SplineImpl {
    size_t n_;
    const double* x_;
    const double* y_;
    double* res_;
    double* res_y_;

    double Interpolate(double x) {
        mySplintCube(x_, y_, res_, n_, x, res_y_);
        return *res_y_;
    }

    ~SplineImpl() {
        free(static_cast<void*>(res_));
        free(static_cast<void*>(res_y_));
    }
};

Spline::Spline(const std::vector<double>& x, const std::vector<double>& y, double a, double b)
    : impl_(std::make_unique<SplineImpl>()) {
    impl_->n_ = x.size();
    impl_->x_ = x.data();
    impl_->y_ = y.data();
    impl_->res_ = static_cast<double*>(malloc(impl_->n_ * sizeof(double)));
    impl_->res_y_ = static_cast<double*>(malloc(sizeof(double)));
    mySplineSnd(impl_->x_, impl_->y_, impl_->n_, a, b, impl_->res_);
}

double Spline::Interpolate(double x) {
    return impl_->Interpolate(x);
}
