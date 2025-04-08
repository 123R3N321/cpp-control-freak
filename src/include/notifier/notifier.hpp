#ifndef NOTIFIER_HPP
#define NOTIFIER_HPP

class Notifier {
private:
    double threshold;

public:
    Notifier(double threshold);
    bool sendAlert(double result);
};

#endif
