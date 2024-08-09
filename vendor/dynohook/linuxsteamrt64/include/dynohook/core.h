#pragma once

#define NONCOPYABLE(x) x(const x&) = delete; \
                       x(x&&) = delete; \
                       x& operator=(const x&) = delete; \
                       x& operator=(x&&) = delete;

#define ITERATABLE(t, o) std::vector<t>::iterator begin() { return o.begin(); } \
                         std::vector<t>::iterator end() { return o.end(); } \
                         std::vector<t>::reverse_iterator rbegin() { return o.rbegin(); } \
                         std::vector<t>::reverse_iterator rend() { return o.rend(); } \
                         [[nodiscard]] std::vector<t>::const_iterator begin() const { return o.begin(); } \
                         [[nodiscard]] std::vector<t>::const_iterator end() const { return o.end(); } \
                         [[nodiscard]] std::vector<t>::const_reverse_iterator rbegin() const { return o.rbegin(); } \
                         [[nodiscard]] std::vector<t>::const_reverse_iterator rend() const { return o.rend(); }     \

