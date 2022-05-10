int getRandomNumber(int min, int max);
double getRandomNumber(double min, double max);
/*double getRandomNumber(double min, double max){
    std::default_random_engine rng(std::random_device { } ());
    std::uniform_real_distribution<double> random_dist(min, max);
    return random_dist(rng);
}*/