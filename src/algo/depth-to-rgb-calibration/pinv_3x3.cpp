// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2020 Intel Corporation. All Rights Reserved.

// Code generated by Matlab Coder

#include <limits>
#include "utils.h"


namespace
{

    static inline bool rtIsNaN( double value ) { return (value != value); }
    static inline bool rtIsInf( double value )
    {
        return (value == std::numeric_limits< double >::infinity()
            || value == -std::numeric_limits< double >::infinity());
    }

    double b_xnrm2( int n, const double x[3], int ix0 )
    {
        double y;
        double scale;
        int kend;
        int k;
        double absxk;
        double t;
        y = 0.0;
        if( n >= 1 )
        {
            if( n == 1 )
            {
                y = std::abs( x[ix0 - 1] );
            }
            else
            {
                scale = 3.3121686421112381E-170;
                kend = ( ix0 + n ) - 1;
                for( k = ix0; k <= kend; k++ )
                {
                    absxk = std::abs( x[k - 1] );
                    if( absxk > scale )
                    {
                        t = scale / absxk;
                        y = 1.0 + y * t * t;
                        scale = absxk;
                    }
                    else
                    {
                        t = absxk / scale;
                        y += t * t;
                    }
                }

                y = scale * std::sqrt( y );
            }
        }

        return y;
    }

    double xnrm2( int n, const double x[9], int ix0 )
    {
        double y;
        double scale;
        int kend;
        int k;
        double absxk;
        double t;
        y = 0.0;
        if( n >= 1 )
        {
            if( n == 1 )
            {
                y = std::abs( x[ix0 - 1] );
            }
            else
            {
                scale = 3.3121686421112381E-170;
                kend = ( ix0 + n ) - 1;
                for( k = ix0; k <= kend; k++ )
                {
                    absxk = std::abs( x[k - 1] );
                    if( absxk > scale )
                    {
                        t = scale / absxk;
                        y = 1.0 + y * t * t;
                        scale = absxk;
                    }
                    else
                    {
                        t = absxk / scale;
                        y += t * t;
                    }
                }

                y = scale * std::sqrt( y );
            }
        }

        return y;
    }

    void b_xaxpy( int n, double a, const double x[9], int ix0, double y[3], int iy0 )
    {
        int ix;
        int iy;
        int i3;
        int k;
        if( ( n < 1 ) || ( a == 0.0 ) )
        {
        }
        else
        {
            ix = ix0 - 1;
            iy = iy0 - 1;
            i3 = n - 1;
            for( k = 0; k <= i3; k++ )
            {
                y[iy] += a * x[ix];
                ix++;
                iy++;
            }
        }
    }

    void c_xaxpy( int n, double a, const double x[3], int ix0, double y[9], int iy0 )
    {
        int ix;
        int iy;
        int i4;
        int k;
        if( ( n < 1 ) || ( a == 0.0 ) )
        {
        }
        else
        {
            ix = ix0 - 1;
            iy = iy0 - 1;
            i4 = n - 1;
            for( k = 0; k <= i4; k++ )
            {
                y[iy] += a * x[ix];
                ix++;
                iy++;
            }
        }
    }

    void xaxpy( int n, double a, int ix0, double y[9], int iy0 )
    {
        int ix;
        int iy;
        int i2;
        int k;
        if( ( n < 1 ) || ( a == 0.0 ) )
        {
        }
        else
        {
            ix = ix0 - 1;
            iy = iy0 - 1;
            i2 = n - 1;
            for( k = 0; k <= i2; k++ )
            {
                y[iy] += a * y[ix];
                ix++;
                iy++;
            }
        }
    }

    double xdotc( int n, const double x[9], int ix0, const double y[9], int iy0 )
    {
        double d;
        int ix;
        int iy;
        int k;
        d = 0.0;
        if( n >= 1 )
        {
            ix = ix0;
            iy = iy0;
            for( k = 0; k < n; k++ )
            {
                d += x[ix - 1] * y[iy - 1];
                ix++;
                iy++;
            }
        }

        return d;
    }

    void xrotg( double * a, double * b, double * c, double * s )
    {
        double roe;
        double absa;
        double absb;
        double scale;
        double ads;
        double bds;
        roe = *b;
        absa = std::abs( *a );
        absb = std::abs( *b );
        if( absa > absb )
        {
            roe = *a;
        }

        scale = absa + absb;
        if( scale == 0.0 )
        {
            *s = 0.0;
            *c = 1.0;
            *a = 0.0;
            *b = 0.0;
        }
        else
        {
            ads = absa / scale;
            bds = absb / scale;
            scale *= std::sqrt( ads * ads + bds * bds );
            if( roe < 0.0 )
            {
                scale = -scale;
            }

            *c = *a / scale;
            *s = *b / scale;
            if( absa > absb )
            {
                *b = *s;
            }
            else if( *c != 0.0 )
            {
                *b = 1.0 / *c;
            }
            else
            {
                *b = 1.0;
            }

            *a = scale;
        }
    }

    void xrot( double x[9], int ix0, int iy0, double c, double s )
    {
        int ix;
        int iy;
        double temp;
        ix = ix0 - 1;
        iy = iy0 - 1;
        temp = c * x[ix] + s * x[iy];
        x[iy] = c * x[iy] - s * x[ix];
        x[ix] = temp;
        iy++;
        ix++;
        temp = c * x[ix] + s * x[iy];
        x[iy] = c * x[iy] - s * x[ix];
        x[ix] = temp;
        iy++;
        ix++;
        temp = c * x[ix] + s * x[iy];
        x[iy] = c * x[iy] - s * x[ix];
        x[ix] = temp;
    }

    void b_sqrt( double * x ) { *x = std::sqrt( *x ); }

    void xswap( double x[9], int ix0, int iy0 )
    {
        int ix;
        int iy;
        double temp;
        ix = ix0 - 1;
        iy = iy0 - 1;
        temp = x[ix];
        x[ix] = x[iy];
        x[iy] = temp;
        ix++;
        iy++;
        temp = x[ix];
        x[ix] = x[iy];
        x[iy] = temp;
        ix++;
        iy++;
        temp = x[ix];
        x[ix] = x[iy];
        x[iy] = temp;
    }



    void svd_3x3( const double A[9], double U[9], double s[3], double V[9] )
    {
        double b_A[9];
        double e[3];
        double work[3];
        double Vf[9];
        bool apply_transform;
        double nrm;
        double b_s[3];
        int kase;
        int qp1;
        int qjj;
        double r;
        int m;
        int q;
        int qq;
        double snorm;
        int exitg1;
        bool exitg2;
        double scale;
        double sm;
        double sqds;
        double b;
        memcpy( &b_A[0], &A[0], 9U * sizeof( double ) );
        e[0] = 0.0;
        work[0] = 0.0;
        e[1] = 0.0;
        work[1] = 0.0;
        e[2] = 0.0;
        work[2] = 0.0;
        memset( &U[0], 0, 9U * sizeof( double ) );
        memset( &Vf[0], 0, 9U * sizeof( double ) );
        apply_transform = false;
        nrm = xnrm2( 3, b_A, 1 );
        if( nrm > 0.0 )
        {
            apply_transform = true;
            if( b_A[0] < 0.0 )
            {
                nrm = -nrm;
            }

            if( std::abs( nrm ) >= 1.0020841800044864E-292 )
            {
                r = 1.0 / nrm;
                for( qp1 = 1; qp1 < 4; qp1++ )
                {
                    b_A[qp1 - 1] *= r;
                }
            }
            else
            {
                for( qp1 = 1; qp1 < 4; qp1++ )
                {
                    b_A[qp1 - 1] /= nrm;
                }
            }

            b_A[0]++;
            b_s[0] = -nrm;
        }
        else
        {
            b_s[0] = 0.0;
        }

        for( kase = 2; kase < 4; kase++ )
        {
            qjj = 3 * (kase - 1);
            if( apply_transform )
            {
                xaxpy( 3, -(xdotc( 3, b_A, 1, b_A, qjj + 1 ) / b_A[0]), 1, b_A, qjj + 1 );
            }

            e[kase - 1] = b_A[qjj];
        }

        for( qp1 = 1; qp1 < 4; qp1++ )
        {
            U[qp1 - 1] = b_A[qp1 - 1];
        }

        nrm = b_xnrm2( 2, e, 2 );
        if( nrm == 0.0 )
        {
            e[0] = 0.0;
        }
        else
        {
            if( e[1] < 0.0 )
            {
                e[0] = -nrm;
            }
            else
            {
                e[0] = nrm;
            }

            r = e[0];
            if( std::abs( e[0] ) >= 1.0020841800044864E-292 )
            {
                r = 1.0 / e[0];
                for( qp1 = 2; qp1 < 4; qp1++ )
                {
                    e[qp1 - 1] *= r;
                }
            }
            else
            {
                for( qp1 = 2; qp1 < 4; qp1++ )
                {
                    e[qp1 - 1] /= r;
                }
            }

            e[1]++;
            e[0] = -e[0];
            for( qp1 = 2; qp1 < 4; qp1++ )
            {
                work[qp1 - 1] = 0.0;
            }

            for( kase = 2; kase < 4; kase++ )
            {
                b_xaxpy( 2, e[kase - 1], b_A, 3 * (kase - 1) + 2, work, 2 );
            }

            for( kase = 2; kase < 4; kase++ )
            {
                c_xaxpy( 2, -e[kase - 1] / e[1], work, 2, b_A, 3 * (kase - 1) + 2 );
            }
        }

        for( qp1 = 2; qp1 < 4; qp1++ )
        {
            Vf[qp1 - 1] = e[qp1 - 1];
        }

        apply_transform = false;
        nrm = xnrm2( 2, b_A, 5 );
        if( nrm > 0.0 )
        {
            apply_transform = true;
            if( b_A[4] < 0.0 )
            {
                nrm = -nrm;
            }

            if( std::abs( nrm ) >= 1.0020841800044864E-292 )
            {
                r = 1.0 / nrm;
                for( qp1 = 5; qp1 < 7; qp1++ )
                {
                    b_A[qp1 - 1] *= r;
                }
            }
            else
            {
                for( qp1 = 5; qp1 < 7; qp1++ )
                {
                    b_A[qp1 - 1] /= nrm;
                }
            }

            b_A[4]++;
            b_s[1] = -nrm;
        }
        else
        {
            b_s[1] = 0.0;
        }

        for( kase = 3; kase < 4; kase++ )
        {
            if( apply_transform )
            {
                xaxpy( 2, -(xdotc( 2, b_A, 5, b_A, 8 ) / b_A[4]), 5, b_A, 8 );
            }
        }

        for( qp1 = 2; qp1 < 4; qp1++ )
        {
            U[qp1 + 2] = b_A[qp1 + 2];
        }

        m = 1;
        b_s[2] = b_A[8];
        e[1] = b_A[7];
        e[2] = 0.0;
        U[6] = 0.0;
        U[7] = 0.0;
        U[8] = 1.0;
        for( q = 1; q >= 0; q-- )
        {
            qp1 = q + 2;
            qq = q + 3 * q;
            if( b_s[q] != 0.0 )
            {
                for( kase = qp1; kase < 4; kase++ )
                {
                    qjj = (q + 3 * (kase - 1)) + 1;
                    xaxpy( 3 - q, -(xdotc( 3 - q, U, qq + 1, U, qjj ) / U[qq]), qq + 1, U, qjj );
                }

                for( qp1 = q + 1; qp1 < 4; qp1++ )
                {
                    kase = (qp1 + 3 * q) - 1;
                    U[kase] = -U[kase];
                }

                U[qq]++;
                if( 0 <= q - 1 )
                {
                    U[3 * q] = 0.0;
                }
            }
            else
            {
                U[3 * q] = 0.0;
                U[1 + 3 * q] = 0.0;
                U[2 + 3 * q] = 0.0;
                U[qq] = 1.0;
            }
        }

        for( q = 2; q >= 0; q-- )
        {
            if( (q + 1 <= 1) && (e[0] != 0.0) )
            {
                xaxpy( 2, -(xdotc( 2, Vf, 2, Vf, 5 ) / Vf[1]), 2, Vf, 5 );
                xaxpy( 2, -(xdotc( 2, Vf, 2, Vf, 8 ) / Vf[1]), 2, Vf, 8 );
            }

            Vf[3 * q] = 0.0;
            Vf[1 + 3 * q] = 0.0;
            Vf[2 + 3 * q] = 0.0;
            Vf[q + 3 * q] = 1.0;
        }

        qq = 0;
        snorm = 0.0;
        for( q = 0; q < 3; q++ )
        {
            if( b_s[q] != 0.0 )
            {
                nrm = std::abs( b_s[q] );
                r = b_s[q] / nrm;
                b_s[q] = nrm;
                if( q + 1 < 3 )
                {
                    e[q] /= r;
                }

                kase = 3 * q;
                qjj = kase + 3;
                for( qp1 = kase + 1; qp1 <= qjj; qp1++ )
                {
                    U[qp1 - 1] *= r;
                }
            }

            if( (q + 1 < 3) && (e[q] != 0.0) )
            {
                nrm = std::abs( e[q] );
                r = nrm / e[q];
                e[q] = nrm;
                b_s[q + 1] *= r;
                kase = 3 * (q + 1);
                qjj = kase + 3;
                for( qp1 = kase + 1; qp1 <= qjj; qp1++ )
                {
                    Vf[qp1 - 1] *= r;
                }
            }

            nrm = std::abs( b_s[q] );
            r = std::abs( e[q] );
            if( (nrm > r) || rtIsNaN( r ) )
            {
                r = nrm;
            }

            if( (!(snorm > r)) && (!rtIsNaN( r )) )
            {
                snorm = r;
            }
        }

        while( (m + 2 > 0) && (qq < 75) )
        {
            qp1 = m;
            do
            {
                exitg1 = 0;
                q = qp1 + 1;
                if( qp1 + 1 == 0 )
                {
                    exitg1 = 1;
                }
                else
                {
                    nrm = std::abs( e[qp1] );
                    if( (nrm <= 2.2204460492503131E-16
                        * (std::abs( b_s[qp1] ) + std::abs( b_s[qp1 + 1] )))
                        || (nrm <= 1.0020841800044864E-292)
                        || ((qq > 20) && (nrm <= 2.2204460492503131E-16 * snorm)) )
                    {
                        e[qp1] = 0.0;
                        exitg1 = 1;
                    }
                    else
                    {
                        qp1--;
                    }
                }
            } while( exitg1 == 0 );

            if( qp1 + 1 == m + 1 )
            {
                kase = 4;
            }
            else
            {
                qjj = m + 2;
                kase = m + 2;
                exitg2 = false;
                while( (!exitg2) && (kase >= qp1 + 1) )
                {
                    qjj = kase;
                    if( kase == qp1 + 1 )
                    {
                        exitg2 = true;
                    }
                    else
                    {
                        nrm = 0.0;
                        if( kase < m + 2 )
                        {
                            nrm = std::abs( e[kase - 1] );
                        }

                        if( kase > qp1 + 2 )
                        {
                            nrm += std::abs( e[kase - 2] );
                        }

                        r = std::abs( b_s[kase - 1] );
                        if( (r <= 2.2204460492503131E-16 * nrm) || (r <= 1.0020841800044864E-292) )
                        {
                            b_s[kase - 1] = 0.0;
                            exitg2 = true;
                        }
                        else
                        {
                            kase--;
                        }
                    }
                }

                if( qjj == qp1 + 1 )
                {
                    kase = 3;
                }
                else if( qjj == m + 2 )
                {
                    kase = 1;
                }
                else
                {
                    kase = 2;
                    q = qjj;
                }
            }

            switch( kase )
            {
            case 1:
                r = e[m];
                e[m] = 0.0;
                qjj = m + 1;
                for( qp1 = qjj; qp1 >= q + 1; qp1-- )
                {
                    xrotg( &b_s[qp1 - 1], &r, &sm, &sqds );
                    if( qp1 > q + 1 )
                    {
                        r = -sqds * e[0];
                        e[0] *= sm;
                    }

                    xrot( Vf, 1 + 3 * (qp1 - 1), 1 + 3 * (m + 1), sm, sqds );
                }
                break;

            case 2:
                r = e[q - 1];
                e[q - 1] = 0.0;
                for( qp1 = q + 1; qp1 <= m + 2; qp1++ )
                {
                    xrotg( &b_s[qp1 - 1], &r, &sm, &sqds );
                    b = e[qp1 - 1];
                    r = -sqds * b;
                    e[qp1 - 1] = b * sm;
                    xrot( U, 1 + 3 * (qp1 - 1), 1 + 3 * (q - 1), sm, sqds );
                }
                break;

            case 3:
                kase = m + 1;
                scale = std::abs( b_s[m + 1] );
                r = std::abs( b_s[m] );
                if( (!(scale > r)) && (!rtIsNaN( r )) )
                {
                    scale = r;
                }

                r = std::abs( e[m] );
                if( (!(scale > r)) && (!rtIsNaN( r )) )
                {
                    scale = r;
                }

                r = std::abs( b_s[q] );
                if( (!(scale > r)) && (!rtIsNaN( r )) )
                {
                    scale = r;
                }

                r = std::abs( e[q] );
                if( (!(scale > r)) && (!rtIsNaN( r )) )
                {
                    scale = r;
                }

                sm = b_s[m + 1] / scale;
                nrm = b_s[m] / scale;
                r = e[m] / scale;
                sqds = b_s[q] / scale;
                b = ((nrm + sm) * (nrm - sm) + r * r) / 2.0;
                nrm = sm * r;
                nrm *= nrm;
                if( (b != 0.0) || (nrm != 0.0) )
                {
                    r = b * b + nrm;
                    b_sqrt( &r );
                    if( b < 0.0 )
                    {
                        r = -r;
                    }

                    r = nrm / (b + r);
                }
                else
                {
                    r = 0.0;
                }

                r += (sqds + sm) * (sqds - sm);
                nrm = sqds * (e[q] / scale);
                for( qp1 = q + 1; qp1 <= kase; qp1++ )
                {
                    xrotg( &r, &nrm, &sm, &sqds );
                    if( qp1 > q + 1 )
                    {
                        e[0] = r;
                    }

                    b = e[qp1 - 1];
                    nrm = b_s[qp1 - 1];
                    e[qp1 - 1] = sm * b - sqds * nrm;
                    r = sqds * b_s[qp1];
                    b_s[qp1] *= sm;
                    xrot( Vf, 1 + 3 * (qp1 - 1), 1 + 3 * qp1, sm, sqds );
                    b_s[qp1 - 1] = sm * nrm + sqds * b;
                    xrotg( &b_s[qp1 - 1], &r, &sm, &sqds );
                    b = e[qp1 - 1];
                    r = sm * b + sqds * b_s[qp1];
                    b_s[qp1] = -sqds * b + sm * b_s[qp1];
                    nrm = sqds * e[qp1];
                    e[qp1] *= sm;
                    xrot( U, 1 + 3 * (qp1 - 1), 1 + 3 * qp1, sm, sqds );
                }

                e[m] = r;
                qq++;
                break;

            default:
                if( b_s[q] < 0.0 )
                {
                    b_s[q] = -b_s[q];
                    kase = 3 * q;
                    qjj = kase + 3;
                    for( qp1 = kase + 1; qp1 <= qjj; qp1++ )
                    {
                        Vf[qp1 - 1] = -Vf[qp1 - 1];
                    }
                }

                qp1 = q + 1;
                while( (q + 1 < 3) && (b_s[q] < b_s[qp1]) )
                {
                    nrm = b_s[q];
                    b_s[q] = b_s[qp1];
                    b_s[qp1] = nrm;
                    xswap( Vf, 1 + 3 * q, 1 + 3 * (q + 1) );
                    xswap( U, 1 + 3 * q, 1 + 3 * (q + 1) );
                    q = qp1;
                    qp1++;
                }

                qq = 0;
                m--;
                break;
            }
        }

        for( qp1 = 0; qp1 < 3; qp1++ )
        {
            s[qp1] = b_s[qp1];
            V[3 * qp1] = Vf[3 * qp1];
            kase = 1 + 3 * qp1;
            V[kase] = Vf[kase];
            kase = 2 + 3 * qp1;
            V[kase] = Vf[kase];
        }
    }

}  // anon namespace


void librealsense::algo::depth_to_rgb_calibration::pinv_3x3( const double m[9], double n[9] )
{
    int br;
    double U[9];
    double s[3];
    double V[9];
    int i0;
    double absxk;
    int vcol;
    int r;
    int j;
    int ar;
    int ib;
    int ia;
    int i1;
    int ic;
    bool p = true;
    for( br = 0; br < 9; br++ )
    {
        n[br] = 0.0;
        if( p && ((!rtIsInf( m[br] )) && (!rtIsNaN( m[br] ))) )
            p = true;
        else
            p = false;
    }

    if( !p )
    {
        for( i0 = 0; i0 < 9; i0++ )
            n[i0] = std::numeric_limits< double >::quiet_NaN();
    }
    else
    {
        svd_3x3( m, U, s, V );
        absxk = std::abs( s[0] );
        if( (!rtIsInf( absxk )) && (!rtIsNaN( absxk )) )
        {
            if( absxk <= 2.2250738585072014E-308 )
            {
                absxk = 4.94065645841247E-324;
            }
            else
            {
                frexp( absxk, &vcol );
                absxk = std::ldexp( 1.0, vcol - 53 );
            }
        }
        else
        {
            absxk = std::numeric_limits< double >::quiet_NaN();
        }

        absxk *= 3.0;
        r = -1;
        br = 0;
        while( (br < 3) && (s[br] > absxk) )
        {
            r++;
            br++;
        }

        if( r + 1 > 0 )
        {
            vcol = 1;
            for( j = 0; j <= r; j++ )
            {
                absxk = 1.0 / s[j];
                i0 = vcol + 2;
                for( br = vcol; br <= i0; br++ )
                {
                    V[br - 1] *= absxk;
                }

                vcol += 3;
            }

            for( vcol = 0; vcol <= 6; vcol += 3 )
            {
                i0 = vcol + 1;
                j = vcol + 3;
                if( i0 <= j )
                {
                    memset( &n[i0 + -1],
                        0,
                        (unsigned int)(((j - i0) + 1)
                            * static_cast<int>(sizeof( double ))) );
                }
            }

            br = 0;
            for( vcol = 0; vcol <= 6; vcol += 3 )
            {
                ar = -1;
                br++;
                i0 = br + 3 * r;
                for( ib = br; ib <= i0; ib += 3 )
                {
                    ia = ar;
                    j = vcol + 1;
                    i1 = vcol + 3;
                    for( ic = j; ic <= i1; ic++ )
                    {
                        ia++;
                        n[ic - 1] += U[ib - 1] * V[ia];
                    }

                    ar += 3;
                }
            }
        }
    }
}
