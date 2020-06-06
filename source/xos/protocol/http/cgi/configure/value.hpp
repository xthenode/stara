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
///   File: value.hpp
///
/// Author: $author$
///   Date: 4/27/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_HTTP_CGI_CONFIGURE_VALUE_HPP
#define XOS_PROTOCOL_HTTP_CGI_CONFIGURE_VALUE_HPP

#include "xos/protocol/http/cgi/configure/which.hpp"
#include "xos/protocol/xttp/message/part.hpp"

namespace xos {
namespace protocol {
namespace http {
namespace cgi {
namespace configure {

/// class valuet
template <class TExtends = xttp::message::part, class TImplements = typename TExtends::implements>
class exported valuet: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef valuet derives;

    typedef extends part_t;
    typedef typename extends::string_t string_t;
    typedef xos::charst<typename string_t::char_t> chars_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructor / destructor
    valuet(configure::which_t which): which_(which), setting_(0) {
    }
    valuet(configure::which_t which, const string_t& chars): which_(which), extends(chars), setting_(0) {
    }
    valuet(configure::which_t which, const char_t* chars): which_(which), extends(chars), setting_(0) {
    }
    valuet(configure::which_t which, const char_t* chars, size_t length): which_(which), extends(chars, length), setting_(0) {
    }
    valuet(const string_t& chars): extends(chars), setting_(0) {
    }
    valuet(const char_t* chars, size_t length): extends(chars, length), setting_(0) {
    }
    valuet(const char_t* chars): extends(chars), setting_(0) {
    }
    valuet(const valuet& copy): extends(copy), which_(copy.which_), setting_(0) {
    }
    valuet(): setting_(0) {
    }
    virtual ~valuet() {
    }

    /// set
    virtual bool set(configure::which_t to) {
        bool success = true;
        this->clear();
        set_which(to);
        return success;
    }
    virtual bool set(configure::which_t to, const string_t& chars) {
        bool success = true;
        set_which(to);
        success = set(chars);
        return success;
    }
    virtual bool set(configure::which_t to, const char_t* chars, size_t length) {
        bool success = true;
        set_which(to);
        success = set(chars, length);
        return success;
    }
    virtual bool set(configure::which_t to, const char_t* chars) {
        bool success = true;
        set_which(to);
        success = set(chars);
        return success;
    }
    virtual bool set(const string_t& to) {
        bool success = true;
        this->clear();
        this->assign(to);
        return success;
    }
    virtual bool set(const char_t* to, size_t length) {
        bool success = true;
        this->clear();
        this->assign(to, length);
        return success;
    }
    virtual bool set(const char_t* to) {
        bool success = true;
        this->clear();
        this->assign(to);
        return success;
    }
    virtual derives& clear() {
        extends::clear();
        clear_setting();
        return *this;
    }

    /// read / write
    virtual bool read(ssize_t& count, char_t& c, reader_t& reader) {
        bool success = false;
        success = this->read_this(count, c, reader);
        return success;
    }
    virtual bool write(ssize_t& count, writer_t& writer) {
        bool success = false;
        success = this->write_this(count, writer);
        return success;
    }

    /// set_default...
    virtual derives& set_default() {
        this->clear();
        set_defaults();
        return *this;
    }
    virtual derives& set_defaults() {
        clear_setting();
        return *this;
    }

    /// of...
    virtual const char* of(size_t& length) const {
        length = of_length();
        return of();
    }
    virtual const char* of() const {
        return which_.name();
    }
    virtual size_t of_length() const {
        size_t length = 0;
        const char* chars = 0;
        if ((chars = of())) {
            length = chars_t::count(chars);
        }
        return length;
    }

    /// ...which
    virtual configure::which_t set_which(configure::which_t to) {
        which_ = to;
        return which();
    }
    virtual configure::which_t which() const {
        return (configure::which_t)which_;
    }

    /// ...setting
    const char_t* set_setting(const char_t* chars) {
        if ((set(chars))) {
            set_setting();
        }
        return setting_;
    }
    const char_t* set_setting() {
        setting_ = this->chars();
        return setting_;
    }
    const char_t* clear_setting() {
        setting_ = 0;
        return setting_;
    }
    const char_t* setting() const {
        return setting_;
    }

protected:
    configure::which which_;
    const char_t* setting_;
}; /// class valuet
typedef valuet<> value;

} /// namespace configure
} /// namespace cgi
} /// namespace http
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_HTTP_CGI_CONFIGURE_VALUE_HPP 