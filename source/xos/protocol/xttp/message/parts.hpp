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
///   File: parts.hpp
///
/// Author: $author$
///   Date: 3/13/2020
///////////////////////////////////////////////////////////////////////
#ifndef XOS_PROTOCOL_XTTP_MESSAGE_PARTS_HPP
#define XOS_PROTOCOL_XTTP_MESSAGE_PARTS_HPP

#include "xos/protocol/xttp/message/part.hpp"
#include "xos/protocol/xttp/message/line.hpp"
#include "xos/protocol/xttp/message/header/fields.hpp"
#include "xos/protocol/xttp/message/body/content.hpp"

namespace xos {
namespace protocol {
namespace xttp {
namespace message {

/// class partst
template 
<class TLine = message::line,
 class TExtends = part, class TImplements = typename TExtends::implements>
class exported partst: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef partst derives;

    typedef TLine line_t;
    typedef header::field field_t;
    typedef header::fields headers_t;
    typedef body::content content_t;
    typedef extends part_t;
    typedef typename extends::string_t string_t;
    typedef typename string_t::char_t char_t;
    typedef typename extends::reader_t reader_t;
    typedef typename extends::writer_t writer_t;

    /// constructor / destructor
    partst(const line_t& line, const headers_t& headers, const content_t* content): line_(line), headers_(headers), content_(content) {
        combine();
    }
    partst(const line_t& line, const headers_t& headers): line_(line), headers_(headers), content_(0) {
        combine();
    }
    partst(const string_t& chars): extends(chars), content_(0) {
        separate();
    }
    partst(const char_t* chars, size_t length): extends(chars, length), content_(0) {
        separate();
    }
    partst(const char_t* chars): extends(chars), content_(0) {
        separate();
    }
    partst(const partst& copy): extends(copy), content_(copy.content_) {
    }
    partst(): content_(0) {
        set_default();
    }
    virtual ~partst() {
    }

    /// read / write
    virtual bool read(ssize_t& count, char_t& c, reader_t& reader) {
        bool success = false;

        set_default();
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
                
                if ((content_)) {
                    if ((content_->write(amount, writer))) {
                        count += amount;
                        success = true;
                    }
                } else {
                    success = true;
                }
            }
        }
        return success;
    }

    /// combine / separate
    virtual bool combine() {
        bool success = false;
        const char_t* chars = 0;

        if ((chars = line_.has_chars())) {
            const field_t* h = 0;
            headers_t::const_iterator_t i;

            this->assignl(chars, "\r\n", NULL);
            if ((h = headers_.first(i))) {
                do {
                    if ((chars = h->has_chars())) {
                        this->appendl(chars, "\r\n", NULL);
                    }
                } while ((h = headers_.next(i)));
            }
            this->appendl("\r\n", NULL);
            return true;
        }
        this->clear();
        return success;
    }
    virtual bool separate() {
        bool success = false;
        const char_t* chars = 0;
        size_t length = 0;

        set_defaults();
        if ((chars = this->has_chars(length))) {
            const char_t *end = chars + length, *first = chars, *last = 0;
            field_t* field = 0;
            char_t c = 0;

            for (bool line = false; chars != end; ++chars) {
                if ('\r' != (c = *chars)) {
                    if ('\n' != (c)) {
                        last = chars;
                    } else {
                        if (last) {
                            if (line) {
                                if ((field = headers_.add_field(first, length = ((last - first) + 1)))) {
                                    headers_.on_add_field(*field);
                                    first += length + 2;
                                    last = 0;
                                } else {
                                    set_defaults();
                                    return false;
                                }
                            } else {
                                if ((line = line_.set(first, length = ((last - first) + 1)))) {
                                    first += length + 2;
                                    last = 0;
                                    success = true;
                                } else {
                                    set_defaults();
                                    return false;
                                }
                            }
                        } else {
                            break;
                        }
                    }
                } else {
                }
            }
        }
        return success;
    }

    /// set_default...
    virtual derives& set_default() {
        this->clear();
        set_defaults();
        combine();
        return *this;
    }
    virtual derives& set_defaults() {
        line_.set_default();
        headers_.set_default();
        return *this;
    }

    /// line / headers / content
    virtual const line_t& line() const {
        return line_;
    }
    virtual const headers_t& headers() const {
        return headers_;
    }
    virtual const content_t* content() const {
        return content_;
    }

protected:
    line_t line_;
    headers_t headers_;
    const content_t* content_;
}; /// class partst
typedef partst<> parts;

} /// namespace message
} /// namespace xttp
} /// namespace protocol
} /// namespace xos

#endif /// ndef XOS_PROTOCOL_XTTP_MESSAGE_PARTS_HPP 
