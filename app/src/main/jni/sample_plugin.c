#include "log.h"
#include "plugin_params.h"
#include <android/log.h>
#include <math.h>

//PI value
#define M_PI 3.14159265358979323846

#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, DEFAULT_LOG_TAG, __VA_ARGS__)



typedef struct {
    int left_gain;

    int right_gain;
} this_plugin_params;

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
    double frequency = 100;
    double sampleRate = sample_rate/frequency;
    unsigned x;
    for (x = 0; x < buffer_frames * output_channels; ++x) {
        output_buffer[x] = sin(2.0 * M_PI * x/sampleRate);
        //LOGW("Sound wave generator: %f", output_buffer[x]);
    }

}

// plugin_process_non_interleaved_t
void process_non_interleaved_buffer(void *context,
                                    int sample_rate,
                                    int buffer_frames,
                                    int input_channels,
                                    const float **input_buffer,
                                    int output_channels,
                                    float **output_buffer) {


        int i, j;

        //Sound wave generator
        double frequency = 100;
        double sampleRate = sample_rate/frequency;
        unsigned x;
        for (x = 0; x < buffer_frames * input_channels; ++x) {
            //output_buffer[x] = sin(2.0 * M_PI * x/sampleRate);
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