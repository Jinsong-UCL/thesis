//
// Created by Marco Paggiaro on 19/01/2021.
//

#ifndef EX1_VIXOPTION_H
#define EX1_VIXOPTION_H
#include <utility>

#include "EuropeanOption.h"

class VIXOption : public EuropeanOption {
public:
    // index needed for computation of displacement:
    int indexTPlusTau = 0;
    // Constructor:
    VIXOption(double K, double T, double r, double kappa, double theta,
              double sigma, double rho, double v0, double S0, std::string  optType,
              unsigned nParameters = 5, double q = 0,
              std::string cfType = "Cui",double N = 200);

    VIXOption(double K, double T, double r, double S0, std::string  optType,
              unsigned nParameters = 5, double q = 0,
              std::string cfType = "Cui",double N = 200);

    double Price() const override;
    std::vector<double> Jacobian() const override;
    void SetIndexTPlusTau();

private:
    std::complex<double> CharFunc(std::complex<double> u) const override;
    std::vector<std::complex<double>> JacobianCF(std::complex<double> u) const override;
    double IntegralPhi() const override;
};


#endif //EX1_VIXOPTION_H
