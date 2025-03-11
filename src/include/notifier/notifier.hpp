#ifndef NOTIFIER_HPP
#define NOTIFIER_HPP

class Notifier {
private:
    double threshold;

public:
    Notifier(double threshold);
    void sendAlert(double result);
};

#endif
