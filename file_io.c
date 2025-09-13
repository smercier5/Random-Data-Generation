#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to generate a random integer in [m, M]
int random_uniform_int(int m, int M) {
    return m + rand() % (M - m + 1);
}

// Function to generate a random real number in [m, M]
double random_uniform_real(double m, double M) {
    return m + ((double)rand() / RAND_MAX) * (M - m);
}

// Function to generate a random normally distributed number (Box-Muller Transform)
double random_normal(double mean, double std_dev) {
    double u1 = (double)rand() / RAND_MAX;
    double u2 = (double)rand() / RAND_MAX;
    double z0 = sqrt(-2.0 * log(u1)) * cos(2.0 * M_PI * u2);
    return mean + z0 * std_dev;
}

// Function to truncate a value to [m, M]
double truncate(double value, double m, double M) {
    if (value < m) return m;
    if (value > M) return M;
    return value;
}

// Function to write data to a CSV file
void write_to_csv(const char *filename, const double *data, int N) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "Value\n");
    for (int i = 0; i < N; i++) {
        fprintf(file, "%f\n", data[i]);
    }

    fclose(file);
    printf("Data written to %s\n", filename);
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Define scenarios
    int num_scenarios = 3;
    double means[] = {5, pow(2, 10), pow(2, 12)};
    double std_devs[] = {1, pow(2, 8), 1.3 * pow(2, 10)};
    double mins[] = {1, 1, 1};
    double maxs[] = {8, 2000, 8100};
    int sample_sizes[] = {20, 200000, 2000000};

    for (int scenario = 0; scenario < num_scenarios; scenario++) {
        double mean = means[scenario];
        double std_dev = std_devs[scenario];
        double min = mins[scenario];
        double max = maxs[scenario];
        int N = sample_sizes[scenario];

        printf("Processing Scenario %d: \u03bc=%.2f, \u03c3=%.2f, m=%.2f, M=%.2f, N=%d\n", 
               scenario + 1, mean, std_dev, min, max, N);

        // Allocate memory for sequences
        double *data = (double *)malloc(N * sizeof(double));
        if (data == NULL) {
            printf("Error: Memory allocation failed.\n");
            return 1;
        }

        // 1. Uniform integers
        for (int i = 0; i < N; i++) {
            data[i] = random_uniform_int((int)min, (int)max);
        }
        write_to_csv("uniform_integers_scenario.csv", data, N);

        // 2. Uniform real numbers
        for (int i = 0; i < N; i++) {
            data[i] = random_uniform_real(min, max);
        }
        write_to_csv("uniform_reals_scenario.csv", data, N);

        // 3. Normally distributed integers
        for (int i = 0; i < N; i++) {
            data[i] = round(random_normal(mean, std_dev));
        }
        write_to_csv("normal_integers_scenario.csv", data, N);

        // 4. Normally distributed real numbers
        for (int i = 0; i < N; i++) {
            data[i] = random_normal(mean, std_dev);
        }
        write_to_csv("normal_reals_scenario.csv", data, N);

        // 5. Truncated normal integers
        for (int i = 0; i < N; i++) {
            data[i] = round(truncate(random_normal(mean, std_dev), min, max));
        }
        write_to_csv("truncated_normal_integers_scenario.csv", data, N);

        // 6. Truncated normal real numbers
        for (int i = 0; i < N; i++) {
            data[i] = truncate(random_normal(mean, std_dev), min, max);
        }
        write_to_csv("truncated_normal_reals_scenario.csv", data, N);

        free(data);
    }

    printf("Program completed successfully.\n");
    return 0;
}

