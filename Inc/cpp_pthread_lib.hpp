#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include <string>
#include <sstream>
//#include <esp_pthread.h>
//#include <freertos/FreeRTOS.h>
//#include <freertos/task.h>
//#include <esp_log.h>

using namespace std::chrono;

/*
const auto sleep_time = seconds
{
    5
};
*/

void print_thread_info(std::string extra);
void print_thread_error(std::string extra);

void thread_func_inherited();

void spawn_another_thread();

void thread_func_any_core();

void thread_func();
void thread_func1();
void thread_func2();

esp_pthread_cfg_t create_config(const char *name, int core_id, int stack, int prio);

