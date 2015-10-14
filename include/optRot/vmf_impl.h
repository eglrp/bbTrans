/* Copyright (c) 2015, Julian Straub <jstraub@csail.mit.edu> Licensed
 * under the MIT license. See the license file LICENSE.
 */

namespace OptRot {
template<uint32_t D>
double ComputeLogvMFtovMFcost(const vMF<D>& vmf_A, const vMF<D>& vmf_B, 
  const Eigen::Matrix<double, D, 1>& mu_B_prime) {
  const double C = log(2.*M_PI) + log(vmf_A.GetPi()) +
    log(vmf_B.GetPi()) + vmf_A.GetLogZ() + vmf_B.GetLogZ();
  const double z_AB = (vmf_A.GetTau()*vmf_A.GetMu() +
      vmf_B.GetTau()*mu_B_prime).norm();
  return C + ComputeLog2SinhOverZ(z_AB);
};

template <uint32_t D>
vMF<D>::vMF(const Eigen::Matrix<double, D, 1>& mu, double tau, double
    pi) : mu_(mu), tau_(tau), pi_(pi)
{}

template <uint32_t D>
double vMF<D>::GetLogZ() const {
  return -ComputeLog2SinhOverZ(tau_) - log(2.*M_PI);
}
}
