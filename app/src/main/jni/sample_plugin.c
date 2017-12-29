#include "log.h"
#include "plugin_params.h"
#include <android/log.h>
#include <math.h>

//PI value
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define SUCCESS 0
#define ERR     1

#define FREQ_A 440.0
#define FREQ_C 1046.502
#define FREQ_D 1174.659

#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, DEFAULT_LOG_TAG, __VA_ARGS__)



typedef struct {
    int left_gain;

    int right_gain;
} this_plugin_params;

/**
    Synthesize sin wave to outBuffer.

    @param samplesCnt number of samples to generate
    @param outBuffer Buffer which will receive sin wave samples. This function allocates the required
           memory

    @return SUCCESS if sin wave generation succeeds, ERR otherwise.
*/
int synth_wave(int samplesCnt, float *outBuffer) {


}

//  plugin_process_interleaved_t
void process_interleaved_buffer(void *context,
                                int sample_rate,
                                int buffer_frames,
                                int input_channels,
                                const float *input_buffer,
                                int output_channels,
                                float *output_buffer){

    int i, j;

    //Sound wave generator
    double frequency = FREQ_D;
    double twoPI = 2.0 * M_PI;
    double angleIncr = twoPI * frequency / (double)sample_rate;
    unsigned x, y;

    for (x = 0; x < buffer_frames; x++) {
        for (y = 0; y < output_channels; y++) {
            int pos = x * output_channels + y;
            output_buffer[pos] = (float) sin(angleIncr * x) + input_buffer[pos];
        }
    }
}

// plugin_process_non_interleaved_t
void process_non_interleaved_buffer(void *context,
                                    int sample_rate,
                                    int buffer_frames,
                                    int input_channels,
                                    const float *input_buffer,
                                    int output_channels,
                                    float *output_buffer) {


    int i, j;

    //Sound wave generator
    double frequency = FREQ_D;
    double twoPI = 2.0 * M_PI;
    double angleIncr = twoPI * frequency / (double)sample_rate;
    unsigned x, y;

    for (x = 0; x < buffer_frames; x++) {
        output_buffer[x] = (float)sin(angleIncr * x) + input_buffer[x];
        output_buffer[x + buffer_frames] = output_buffer[x];
    }
}

void init_params(void** result) {
    this_plugin_params* params = (this_plugin_params *) malloc(sizeof(this_plugin_params));
    params->left_gain = 1;
    params->right_gain = 1;
    *result = params;
}

void on_value_updated(void* context, int id, int value) {
    this_plugin_params* params = (this_plugin_params *) context;

    if (id == 1) {
        __sync_bool_compare_and_swap(&params->left_gain, params->left_gain, value);
    } else if (id == 2) {
        __sync_bool_compare_and_swap(&params->right_gain, params->right_gain, value);
    }
}

void apply_config(char* config_str) {}

void update_parameter(){}