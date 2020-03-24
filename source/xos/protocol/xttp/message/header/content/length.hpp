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
///   File: length.hpp
///
/// Author: $author$
///   Date: 3/12/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_XTTP_MESSAGE_HEADER_CONTENT_LENGTH_HPP
#define XOS_PROTOCOL_XTTP_MESSAGE_HEADER_CONTENT_LENGTH_HPP

#include "xos/protocol/xttp/message/header/field.hpp"
#include "xos/protocol/xttp/message/body/content.hpp"

namespace xos {
namespace protocol {
namespace xttp {
namespace message {
namespace header {
namespace content {

/// class lengtht
template <class TExtends = header::field, class TImplements = typename TExtends::implements>
class exported lengtht: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef lengtht derives;

    typedef message::body::content content_t;
    typedef extends part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructor / destructor
    lengtht(const content_t& content) {
        set_length(content);
    }
    lengtht(const string_t& chars) {
        set_length(chars);
    }
    lengtht(const char_t* chars, size_t length) {
        set_length(chars, length);
    }
    lengtht(const char_t* chars) {
        set_length(chars);
    }
    lengtht(const lengtht& copy) {
        set_length(copy.value());
    }
    lengtht() {
        set_length();
    }
    virtual ~lengtht() {
    }

    /// set_length
    virtual derives& set_length(const content_t& content) {
        string_t s;
        s.assign_unsigned(content.length());
        this->set_name(name_chars());
        this->set_value(s);
        return *this;
    }
    virtual derives& set_length(const string_t& s) {
        this->set_name(name_chars());
        this->set_value(s);
        return *this;
    }
    virtual derives& set_length(const char* chars, size_t length) {
        this->set_name(name_chars());
        this->set_value(chars, length);
        return *this;
    }
    virtual derives& set_length(const char* chars) {
        this->set_name(name_chars());
        this->set_value(chars);
        return *this;
    }
    virtual derives& set_length() {
        this->set_name(name_chars());
        this->set_value(default_value_chars());
        return *this;
    }
    
    /// ...chars
    const char_t* name_chars() const {
        return "Content-Length";
    }
    const char_t* default_value_chars() const {
        return "0";
    }
}; /// class lengtht
typedef lengtht<> length;

} /// namespace content
} /// namespace header
} /// namespace message
} /// namespace xttp
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_XTTP_MESSAGE_HEADER_CONTENT_LENGTH_HPP 
