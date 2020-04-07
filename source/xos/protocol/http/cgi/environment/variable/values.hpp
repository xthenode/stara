///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2020 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: values.hpp
///
/// Author: $author$
///   Date: 4/6/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_HTTP_CGI_ENVIRONMENT_VARIABLE_VALUES_HPP
#define XOS_PROTOCOL_HTTP_CGI_ENVIRONMENT_VARIABLE_VALUES_HPP

#include "xos/protocol/http/cgi/environment/variable/value.hpp"
#include "xos/base/array.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace cgi {
namespace environment {
namespace variable {

/// class valuest
template 
<class TExtends = arrayt<variable::value, variable::count>, 
 class TImplements = typename TExtends::implements>
class exported valuest: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef valuest derives;

    typedef variable::value value_t;
    typedef variable::value::part_t part_t;
    typedef variable::value::string_t string_t;
    typedef variable::value::chars_t chars_t;
    typedef variable::value::string_t::char_t char_t;
    typedef variable::value::reader_t reader_t;
    typedef variable::value::writer_t writer_t;

    /// constructor / destructor
    valuest(const valuest& copy) {
        init();
    }
    valuest() {
        init();
    }
    virtual ~valuest() {
    }

    /// get
    virtual int get(int argc, char_t** argv, char_t** env) {
        init();
        if ((env) && (env[0])) {
            const char_t *chars = 0, *end = 0; int count = 0;
            variable::which_t which = variable::none;
            value_t* value = 0;
            string_t name;

            for (int i = 1; (chars = env[i]); ++i) {
                if ((chars[0])) {
                    LOGGER_IS_LOGGED_DEBUG("...env[" << i << "] = \"" << chars << "\"");
                    if ((end = end_of_name(chars)) && (end[0])) {
                        name.assign(chars, end - chars);
                        if (variable::none != (which = variable::which::of_name(name.chars()))) {
                            if ((value = value_of(which))) {
                                LOGGER_IS_LOGGED_DEBUG("..." << name << " = \"" << (end +1) << "\"");
                                value->set_setting(end + 1);
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }

    /// first / next
    virtual value_t* first(variable::which_t& which) const {
        value_t* value = 0;
        for (which = variable::first; which <= variable::last; ++which) {
            if ((value = value_of(which))) {
                return value;
            }
        }
        return 0;
    }
    virtual value_t* next(variable::which_t& which) const {
        if ((which < variable::last)) {
            value_t* value = 0;
            do {
                if ((value = value_of(++which))) {
                    return value;
                }
            } while (which <= variable::last);
        }
        return 0;
    }

    /// value
    virtual value_t* value_of(const char_t* name) const {
        value_t& value = operator[](name);
        if ((&null_ != (&value)) && (variable::none != (value.which()))) {
            return &value;
        }
        return 0;
    }
    virtual value_t* value_of(variable::which_t which) const {
        value_t& value = operator[](which);
        if ((&null_ != (&value)) && (variable::none != (value.which()))) {
            return &value;
        }
        return 0;
    }

    /// operator[]
    virtual value_t& operator[](const char_t* name) const {
        variable::which_t which = variable::which::of_name(name);
        if ((which >= variable::first) && (which <= variable::last)) {
            return (value_t&)(extends::operator[](which - variable::first));
        }
        return (value_t&)null_;
    }
    virtual value_t& operator[](variable::which_t which) const {
        if ((which >= variable::first) && (which <= variable::last)) {
            return (value_t&)(extends::operator[](which - variable::first));
        }
        return (value_t&)null_;
    }
    
    /// ...is_logged
    virtual bool set_is_logged(bool to = true) {
        return logged_.set_is_logged(to);
    }
    virtual bool is_logged() const {
        return logged_.is_logged();
    }

protected:
    /// init
    virtual valuest& init() {
        value_t* value = 0; size_t size = 0;
        if ((value = this->elements()) && (variable::count <= (size = this->size()))) {
            for (variable::which_t which = variable::first; which <= variable::last; ++which) {
                value_t& v = value[which - variable::first];
                v.set_which(which);
                v.clear();
            }
        }
        return *this;
    }

    /// end_of_name
    virtual const char_t* end_of_name(const char_t* chars) const {
        const char_t* name = 0;
        if ((name = chars) && (name[0])) {
            for (char_t end = '=', c = *(name); c; c = *(++name)) {
                if (end == c) {
                    if (name != chars) {
                        return name;
                    }
                    break;
                }
            }
        }
        return 0;
    }

protected:
    value_t null_;
    xos::extended::logged logged_;
}; /// class valuest
typedef valuest<> values;

} /// namespace variable
} /// namespace environment
} /// namespace cgi
} /// namespace http
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_HTTP_CGI_ENVIRONMENT_VARIABLE_VALUES_HPP 
