#include "catmull_rom_interpolation.h"

#include <Eigen/Dense>
#include <iostream>
using namespace std;
Eigen::Vector3d catmull_rom_interpolation(
    const std::vector<std::pair<double, Eigen::Vector3d>> &keyframes,
    double t) {
    /////////////////////////////////////////////////////////////////////////////
    // Replace with your code
    // c(t) = (2t^3 + 3t^2 + 1)theta0 + (t^3 -2t^2 +t)m0 + (-2t^3 + 3t^2)theta1
    // + (t^3-t^2)m1 t = (t'-t0)/(t1-t0) mk = thek+1 - thetak / tk+1 -tk

    if (keyframes.size() == 0) {
        return Eigen::Vector3d(0, 0, 0);
    }
    if (keyframes.size() == 1) {
        return keyframes[0].second;
    }

    // t1-t0
    double interval =
        keyframes[keyframes.size() - 1].first - keyframes[0].first;

    double t_new = keyframes[0].first + std::fmod(t, interval);

    int i = 0;
    for (i = 0; i < keyframes.size(); i++) {
        if (keyframes[i].first == t_new) {
            return keyframes[i].second;
        } else if (t_new > keyframes[i].first) {
            continue;
        } else {
            break;
        }
    }
    double t_0;
    double t_2;
    Eigen::Vector3d theta_0;
    Eigen::Vector3d theta_2;

    double t_1 = keyframes[i].first;
    Eigen::Vector3d theta_1 = keyframes[i].second;

    // I thought we needed these checks to make sure the index is not out of
    // range but somehow it still works without it and doesn't seg fault????
    // if (i == 0) {
    //     cout << "HERE" << endl;
    //     t_0 = keyframes[0].first;
    //     theta_0 = keyframes[0].second;
    // } else {
    //     t_0 = keyframes[i - 1].first;
    //     theta_0 = keyframes[i - 1].second;
    // }

    // if (i + 1 == keyframes.size()) {
    //     cout << "I+1" << endl;
    //     t_2 = keyframes[keyframes.size() - 1].first;
    //     theta_2 = keyframes[keyframes.size() - 1].second;
    // } else {
    //     t_2 = keyframes[i + 1].first;
    //     theta_2 = keyframes[i + 1].second;
    // }

    // cout << "Size:" << endl;
    // cout << keyframes.size() << endl;
    // cout << "I:" << endl;
    // cout << i << endl;

    t_0 = keyframes[i - 1].first;
    theta_0 = keyframes[i - 1].second;

    t_2 = keyframes[i + 1].first;
    theta_2 = keyframes[i + 1].second;

    double arbitrary_t = (t_new - t_0) / (t_1 - t_0);

    Eigen::Vector3d m_0 = (theta_1 - theta_0) / (t_1 - t_0);
    Eigen::Vector3d m_1 = (theta_2 - theta_1) / (t_2 - t_1);

    Eigen::Vector3d c;

    c = (2 * pow(arbitrary_t, 3) - 3 * pow(arbitrary_t, 2) + 1) * theta_0 +
        (pow(arbitrary_t, 3) - 2 * pow(arbitrary_t, 2) + arbitrary_t) * m_0 +
        (-2 * pow(arbitrary_t, 3) + 3 * pow(arbitrary_t, 2)) * theta_1 +
        (pow(arbitrary_t, 3) - pow(arbitrary_t, 2)) * m_1;

    return c;
    /////////////////////////////////////////////////////////////////////////////
}
