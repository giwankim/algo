#include <cstdio>
#include <vector>
#include <random>

float Lerp(float a, float b, float t)
{
    return a * (1.0f - t) + b * t;
}

float Variance_2Pass(const std::vector<float> &data)
{
    float average_value = {};
    for (size_t index = 0; index < data.size(); ++index)
    {
        average_value = Lerp(average_value, data[index], 1.0f / float(index + 1));
    }

    float average_error_squared = {};
    for (size_t index = 0; index < data.size(); ++index)
    {
        float error_squared = data[index] - average_value;
        error_squared *= error_squared;
        average_error_squared = Lerp(average_error_squared, error_squared, 1.0f / float(index + 1));
    }
    return average_error_squared;
}

float Variance_1Pass(const std::vector<float> &data)
{
    float average_value = {};
    float average_value_squared = {};
    for (size_t index = 0; index < data.size(); ++index)
    {
        float value = data[index];
        average_value = Lerp(average_value, value, 1.0f / float(index + 1));
        average_value_squared = Lerp(average_value_squared, value * value, 1.0f / float(index + 1));
    }
    return average_value_squared - (average_value * average_value);
}

float Average(const std::vector<float>& values)
{
    float average = {};
    for (size_t index = 0; index < values.size(); ++index)
    {
        average = Lerp(average, values[index], 1.0f / float(index + 1));
    }
    return average;
}

void TestValues(const std::vector<float>& values, const char *label)
{
    float variance1Pass = Variance_1Pass(values);
    float variance2Pass = Variance_2Pass(values);
    float diff = abs(variance1Pass - variance2Pass);

    printf("===== %s =====\n", label);
    printf("Calculating variance of %zu numbers...\n\n", values.size());
    printf("1 Pass = %f\n2 Pass = %f\nDifference = %f\n\n", variance1Pass, variance2Pass, diff);
    printf("mean = %f\n", Average(values));
    printf("std dev = %f\n", sqrt(variance1Pass));
}

int main(int argc, char const *argv[])
{
    // Test uniform distribution
    {
        static const unsigned int c_numValues = 1000;

        std::random_device rd;
        std::mt19937 rng(rd());
        std::uniform_real_distribution<float> dist(-1000.0f, 1000.0f);

        std::vector<float> values(c_numValues);
        for (float &f : values)
        {
            f = dist(rng);
        }

        TestValues(values, "Uniform");
    }

    // Test normal distribution
    {
        static const unsigned int c_numValues = 1000;

        std::random_device rd;
        std::mt19937 rng(rd());
        std::normal_distribution<float> dist(100.0f, 20.0f);

        std::vector<float> values(c_numValues);
        for (float &f : values)
        {
            f = dist(rng);
        }

        TestValues(values, "Normal");
    }

    return 0;
}
