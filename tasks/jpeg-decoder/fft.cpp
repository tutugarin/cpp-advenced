#include "fft.h"

#include <fftw3.h>

#include <exception>
#include <stdexcept>
#include <math.h>

DctCalculator::DctCalculator(size_t width, std::vector<double> *input, std::vector<double> *output)
    : width_(width), input_(input), output_(output) {
    if (input->size() != width * width || output->size() != input->size()) {
        throw std::invalid_argument("Wrong arguments!");
    }
}

void DctCalculator::Inverse() {
    for (size_t i = 0; i != width_ * width_; i += width_) {
        input_->data()[i] *= sqrt(2);
    }
    for (size_t i = 0; i != width_; ++i) {
        input_->data()[i] *= sqrt(2);
    }

    fftw_plan plan = fftw_plan_r2r_2d(width_, width_, input_->data(), output_->data(), FFTW_REDFT01,
                                      FFTW_REDFT01, FFTW_ESTIMATE);
    fftw_execute(plan);
    fftw_destroy_plan(plan);
    fftw_cleanup();

    for (double &elem : *output_) {
        elem /= 16;
    }
}
