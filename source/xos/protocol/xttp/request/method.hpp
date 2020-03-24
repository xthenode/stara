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
///   File: method.hpp
///
/// Author: $author$
///   Date: 3/13/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_XTTP_REQUEST_METHOD_HPP
#define XOS_PROTOCOL_XTTP_REQUEST_METHOD_HPP

#include "xos/protocol/xttp/message/part.hpp"

namespace xos {
namespace protocol {
namespace xttp {
namespace request {

/// class methodt
template 
<typename TWhich = int, TWhich VNone = 0, 
 class TExtends = message::part, class TImplements = typename TExtends::implements>
class exported methodt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef methodt derives;

    typedef TWhich which_t;
    enum { none = VNone };
    typedef extends part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructor / destructor
    methodt(const string_t &copy): extends(copy), which_(none) {
        set_which();
    }
    methodt(const char_t* chars, size_t length): extends(chars, length), which_(none) {
        set_which();
    }
    methodt(const char_t* chars): extends(chars), which_(none) {
        set_which();
    }
    methodt(const methodt& copy): extends(copy), which_(copy.which_) {
    }
    methodt(): which_(none) {
        set_default();
    }
    virtual ~methodt() {
    }
    
    /// read / write
    virtual bool read(ssize_t& count, char_t& c, reader_t& reader) {
        bool success = false;
        ssize_t amount = 0;
        string_t chars;
        
        set_default();
        do {
            if (0 < (amount = reader.read(&c, 1))) {
                count += amount;
                if (('/' != c) && (' ' != c) && ('\r' != c) && ('\n' != c)) {
                    chars.append(&c, 1);
                } else {
                    break;
                }
            } else {
                count = amount;
                return false;
            }
        } while (0 < amount);
        if ((chars.has_chars())) {
            this->assign(chars);
            success = true;
        }
        return success;
    }
    virtual bool write(ssize_t& count, writer_t& writer) {
        bool success = false;
        const char_t* chars = 0;
        size_t length = 0;
        
        if ((chars = this->has_chars(length))) {
            ssize_t amount = 0;

            if (length <= (amount = writer.write(chars, length))) {
                count = amount;
                success = true;
            }
        }
        return success;
    }

    /// set_default...
    virtual derives& set_default() {
        this->clear();
        set_defaults();
        return *this;
    }
    virtual derives& set_defaults() {
        this->assign(name_of_chars(which_ = default_which()));
        return *this;
    }

    /// ...name / ...which
    virtual string_t set_name() {
        string_t name(name_of_chars(which_));
        this->assign(name);
        return name;
    }
    virtual which_t set_which() {
        which_ = of_name(this->chars());
        return which_;
    }
    virtual which_t which() const {
        return which_;
    }

    /// ...of...
    virtual which_t of_name(const string_t& name) const {
        return of_name(name.chars());
    }
    virtual which_t of_name(const char_t* name) const {
        return none;
    }
    virtual string_t name_of(which_t which) const {
        string name(name_of_chars(which));
        return name;
    }
    virtual const char_t* name_of_chars(which_t which) const {
        return default_name_chars();
    }

    /// ...name_chars / ...which
    virtual const char_t* default_name_chars() const {
        return "GET";
    }
    virtual which_t default_which() const {
        return none;
    }

protected:
    which_t which_;
}; /// class methodt
typedef methodt<> method;

} /// namespace request
} /// namespace xttp
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_XTTP_REQUEST_METHOD_HPP 
