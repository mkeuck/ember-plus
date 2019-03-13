/*
    libember -- C++ 03 implementation of the Ember+ Protocol

    Copyright (C) 2012-2016 Lawo GmbH (http://www.lawo.com).
    Distributed under the Boost Software License, Version 1.0.
    (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef __LIBEMBER_GLOW_UTIL_TRAITS_VALUECONVERTERTRAITS_HPP
#define __LIBEMBER_GLOW_UTIL_TRAITS_VALUECONVERTERTRAITS_HPP


#include "../../../ber/Value.hpp"

//SimianIgnore

namespace libember { namespace glow { namespace util
{   
    namespace detail
    {
        template<typename T>
        struct IntegerValueConverterTraits
        {
            typedef T value_type;

            static value_type valueOf(ber::Value const& value, value_type const& default_)
            {
                if (value.typeId() == typeid(int))
                {
                    return static_cast<value_type>(value.as<int>());
                }
                else if (value.typeId() == typeid(unsigned int))
                {
                    return static_cast<value_type>(value.as<unsigned int>());
                }
                else if (value.typeId() == typeid(long))
                {
                    return static_cast<value_type>(value.as<long>());
                }
                else if (value.typeId() == typeid(unsigned long))
                {
                    return static_cast<value_type>(value.as<unsigned long>());
                }
                else if (value.typeId() == typeid(long long))
                {
                    return static_cast<value_type>(value.as<long long>());
                }
                else if (value.typeId() == typeid(unsigned long long))
                {
                    return static_cast<value_type>(value.as<unsigned long long>());
                }

                return default_;
            }
        };
    }

    /**
     * Default implementation for a value converter.
     */
    template<typename DestType>
    struct ValueConverterTraits
    {
        typedef DestType value_type;
            
        static value_type valueOf(ber::Value const& value, value_type const&)
        {
            return value.as<DestType>();
        }
    };

    /**
     * This specialization checks whether the leaf contains an integer value and
     * safely converts it to the int type.
     */
    template<>
    struct ValueConverterTraits<int> : detail::IntegerValueConverterTraits<int>
    {
    };

    /**
     * This specialization checks whether the leaf contains an integer value and
     * safely converts it to the long type.
     */
    template<>
    struct ValueConverterTraits<long> : detail::IntegerValueConverterTraits<long>
    {
    };

    /**
     * This specialization checks whether the leaf contains an integer value and
     * safely converts it to the long long type.
     */
    template<>
    struct ValueConverterTraits<long long> : detail::IntegerValueConverterTraits<long long>
    {
    };

    /**
     * This specialization checks whether the leaf contains an integer value and
     * safely converts it to the unsigned int type.
     */
    template<>
    struct ValueConverterTraits<unsigned int> : detail::IntegerValueConverterTraits<unsigned int>
    {
    };

    /**
     * This specialization checks whether the leaf contains an integer value and
     * safely converts it to the unsigned long type.
     */
    template<>
    struct ValueConverterTraits<unsigned long> : detail::IntegerValueConverterTraits<unsigned long>
    {
    };

    /**
     * This specialization checks whether the leaf contains an integer value and
     * safely converts it to the unsigned long long type.
     */
    template<>
    struct ValueConverterTraits<unsigned long long> : detail::IntegerValueConverterTraits<unsigned long long>
    {
    };

    /**
     * This specialization checks whether the leaf contains an float or double value and
     * safely converts it.
     */
    template<>
    struct ValueConverterTraits<float>
    {
        typedef float value_type;

        static value_type valueOf(ber::Value const& value, value_type const& default_)
        {
            if (value.typeId() == typeid(float))
            {
                return value.as<float>();
            }
            else if (value.typeId() == typeid(double))
            {
                return static_cast<value_type>(value.as<double>());
            }
            return default_;
        }
    };

    /**
     * This specialization checks whether the leaf contains an float or double value and
     * safely converts it.
     */
    template<>
    struct ValueConverterTraits<double>
    {
        typedef double value_type;

        static value_type valueOf(ber::Value const& value, value_type const& default_)
        {
            if (value.typeId() == typeid(float))
            {
                return value.as<float>();
            }
            else if (value.typeId() == typeid(double))
            {
                return value.as<double>();
            }
            return default_;
        }
    };
}
}
}

//EndSimianIgnore

#endif //  __LIBEMBER_GLOW_UTIL_TRAITS_VALUECONVERTERTRAITS_HPP
