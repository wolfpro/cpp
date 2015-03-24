#include <iostream>
#include <cstdio>
#include <vector>
long long Sans = 0, Scans = 0, Smans = 0, Scmans = 0;
long long Dans = 0, Dcans = 0,  Dmans = 0, Dmcans = 0;

long long mainS(long long n, long long m, long long k)
{
    /* long long n, m, k;
     std::cin >> n >> m >> k;*/

    /*long long col[k + 1];
    for (long long i = 0; i < k; ++i) {
        col[i] = 0;
    }*/
    std::vector<long long> col(k + 1, 0);
    //col.resize(k + 1);

    long long t = 0;
    long long ans = 0, cans = 0, mans = 0, cmans = 100000000000000;
    for (long long i = 0; i < m + n + 1; ++i) {
        // std::cout << i << " ";
        if (i < std::min(m, n)) {
            col[i % k] += (i + 1);
            // std::cout << i % k << "+" << i + 1 << std::endl;
        }
        if (i == std::min(m, n)) {
            t = i + 1;
            col[i % k] += i + 1;
            //std::cout << i % k << "+" << i + 1 << std::endl;
        }
        if (std::min(m, n) < i && i <= std::max(m, n)) {
            col[i % k] += t;
            ///std::cout << i % k << "+" << t << std::endl;
        }
        if (std::max(m, n) < i) {
            col[i % k] += m + n - i + 1;
            //std::cout << i % k << "+" <<  m + n - i + 1 << std::endl;
        }
    }
    //std::cout << m << " " << n << " " << k << std::endl;
    //std::cout << ":";
    for (long long i = 0; i < k; ++i) {
        // std::cout << col[i] << " ";
        if (col[i] > cans) {
            ans = i;
            cans = col[i];
        }
        if (col[i] < cmans) {
            mans = i;
            cmans = col[i];
        }
    }
    //std::cout << "\n";

    // return long long[]a = {cans, cmans};
    // return cans;
    /*std::cout << ans + 1 << " " << cans << std::endl;
    std::cout << mans + 1 << " " << cmans << std::endl; */

    /*  if (col[k - 1] != cmans || ((m + 1) * (n + 1) - k) / k != mans) {
          std::cout << n << " " << m << " " << k << std::endl;
          for (long long i = 0; i < k; ++i) {
              std::cout << col[i] << " ";
              if (col[i] > cans) {
                  ans = i;
                  cans = col[i];
              }
              if (col[i] < cmans) {
                  mans = i;
                  cmans = col[i];
              }
          }
      }
      std::cout << std::endl;*/

    Sans = ans + 1;
    Scans = cans;
    Smans = mans + 1;
    Scmans = cmans;

    // std::cout << Sans << " " << Scans << std::endl;
    // std::cout << Smans << " " << Scmans << std::endl;
    return 0;
}

long long fmax(long long a, long long b) {
    if (a >= b)
        return a;
    return b;
}
long long fmin(long long a, long long b) {
    if (a <= b)
        return a;
    return b;
}

void mainMD(long long m, long long n, long long k) {

    //long long m, n, k;
    //std::cin >> n >> m >>  k;

    long long I = 0, II = 0, III = 0;
    long long min = fmin(n, m), max = fmax(n, m);

    long long N = (min + k) / k; // количество цветов на 1ом участке;
    long long t = (min + 1) % k + 1; // номер искомого цвета;

    // std::cout << "t=" << t << std::endl;

    I = (t + N) * N / 2;

    N = (max + k) / k - (min + k) / k;
    II = N * (min + 1);
    //std::cout << "N=" << N << std::endl;

    N = (max + min + k) / k - (max + k) / k;


    //std::cout << "N=" << N << std::endl;
    if (N == 1) {
        III = (m + n + 2 - ((max + k) / k * k + t) + 1 + (m + n + 2 - ((max + min + k + 1) / k * (k) - k + t) + 1)) * N;
    } else
        III = (m + n + 2 - ((max + k) / k * k + t) + 1 + (m + n + 2 - ((max + min + k + 1) / k * (k) - k + t) + 1)) * N / 2;
    // std::cout << "S=" <<  (m + n + 2 - ((max + min + k + 1) / k * (k) - k + t) + 1) << std::endl;

    long long ans = fmax(I, 0) + fmax(II, 0) + fmax(III, 0);
    // std::cout << ":" << I << " " << II << " " << III << std::endl;

    //ans!!! std::cout << N << " " << ans << std::endl;
    Dmans = (min + k) % k + 1;
    Dmcans = ans;

    // / std::cout << Dmans << " " << Dmcans << std::endl;

    return ;
}

int mainD(long long m, long long n, long long k) {

    //long long m, n, k;
    //std::cin >> n >> m >>  k;

    long long I = 0, II = 0, III = 0;
    long long min = fmin(n, m), max = fmax(n, m);

    long long N = (min + k) / k; // количество цветов на 1ом участке;
    long long t = (min + 1) % k + 1; // номер искомого цвета;
    if ((min + 1) % k == 0 ) {
        t = k - 1;
    }
    if (t == 0)
        t++;
    Dans = t;

    //std::cout << "t=" << t << std::endl;

    if (N == 1)
        I = (t + N) * N;
    else
        I = (t + N) * N / 2;


    N = (max + k) / k - (min + k) / k;
    II = N * (min + 1);
    //std::cout << "N=" << N << std::endl;

    N = (max + min + k) / k - (max + k) / k;


    //std::cout << "N=" << N << std::endl;
    if (N == 1) {
        III = (m + n + 1 - ((max + k) / k * k + t - 1) + (m + n + 2 - ((max + min + k + 1) / k * (k) - k + t) + 1)) * N;
    } else
        III = (m + n + 1 - ((max + k) / k * k + t) + (m + n + 2 - ((max + min + k + 1) / k * (k) - k + t) + 1)) * N / 2;


    std::cout << "S=" << (m + n + 1 - ((max + k) / k * k + t - 1)) << std::endl;

    // f ()

    long long ans = fmax(I, 0) + fmax(II, 0) + fmax(III, 0);
    if (k == 1) {
        ans = (n + 1) * (m + 1);
    }

    std::cout << ":" << I << " " << II << " " << III << std::endl;

    //ans!!! std::cout << N << " " << ans << std::endl;


    Dcans = ans;

    // std::cout << Dans << " " << Dcans << std::endl;

    mainMD(m, n, k);
    return 0;
}

long long Aans = 0;
long long Abans = 0;

long long Amans = 0;
long long Abmans = 0;
long long Dbans = 0;

int mainA(long long m, long long n, long long k) {
    long long min = std::min(n, m), max = std::max(n, m), ans = 0, bans = 0;

    //std::cout << min << " ";
    Aans = min % k + 1;
    Abans =  min % k;

    /*if (Abans == 0) {
        Abans += 2;
    }*/
    /*  for (int i = Aans; i < min; i += k) {
          ans += i + 1;
      }*/
    for (int i = Aans - 1; i < m + n + 2; i += k) {
        if (i <= min) {
            ans += (i + 1);
            continue;
        }
        if (min < i && i <= max) {
            // col[i % k] += t;
            ans += (min + 1);
            continue;
            ///std::cout << i % k << "+" << t << std::endl;
        }
        if (max < i) {
            ans += (m + n - i + 1);
            continue;
            // col[i % k] += m + n - i + 1;
            //std::cout << i % k << "+" <<  m + n - i + 1 << std::endl;
        }
    }

    long long dbans = 0;
    /* if (Abans == 0) {
         Abans == +2;
     }*/
    bool flag = false;
    if (Abans == 0) {
        flag = true;
    }
    for (int i = Abans - 1; i < m + n + 2; i += k) {
        if (!flag)
            if (i <= min) {
                bans += (i + 1);
                //continue;
            } else if (min < i && i <= max) {
                // col[i % k] += t;
                bans += (min + 1);
                //continue;
                ///std::cout << i % k << "+" << t << std::endl;
            } else if (max < i) {
                bans += (m + n - i + 1);
                // continue;
                // col[i % k] += m + n - i + 1;
                //std::cout << i % k << "+" <<  m + n - i + 1 << std::endl;
            }


        if (i + 2 <= min) {
            dbans += (i + 3);
            //continue;
        } else if (min < i + 2 && i + 2 <= max) {
            // col[i % k] += t;
            dbans += (min + 1);
            // / continue;
            ///std::cout << i % k << "+" << t << std::endl;
        } else if (max < i + 2 && i + 2 < m + n + 2) {
            dbans += (m + n - i - 1);
            //continue;
            // col[i % k] += m + n - i + 1;
            //std::cout << i % k << "+" <<  m + n - i + 1 << std::endl;

        }
    }
    Dbans = dbans;
    /*long long tbans = 0;
    if (Abans > 0) {
        tbans = fmin(dbans, bans);
        if (dbans == fmin(dbans, bans)) {
            Abans += 2;
        }
        bans = tbans;
    }*/

    if (flag) {
        Abans += 2;
        bans = dbans;
    } else if (dbans == fmin(dbans, bans) && Abans + 1 < k && bans != fmin(dbans, bans)) {
        Abans += 2;
        bans = dbans;
    }

    Amans = ans;
    Abmans = bans;

    if (k == 1) {
        Abmans = ans;
        return 0;
    }

    //Acans = bans;


    // std::cout << ans << std::endl;
    // / ans++;


}

int main()
{
    /*  long long n, m, k;
      std::cin >> n >> m >> k;
      mainD(n, m , k);
      mainS(n, m, k);*/
    int end = 0;
    for (long long i = 2; i <= 1000; ++i) {
        for (long long j = i; j <= 1000; ++j) {
            for (long long n = 1; n <= i + j; ++n) {
                /*  i = 2;
                  j = 3;
                  n = 2;*/

                mainD(i, j, n);
                // mainA(i, j, n);
                mainS(i, j, n);
                //  std::cout << Sans << " " << Scans << " " << Dans << " " << Dcans <<  " NO \n";

                if ( Scans != Dcans) { //} || Scmans != Dmcans) { //} || Smans != Dmans || Scmans != Dcmans) {
                    std::cout << i << " " << j << " " << n << std::endl;
                    std::cout << Sans << " " << Scans << " " << Dans << " " << Dcans <<  " NO \n";
                    return 0;
                }
                if (Dans * Dmcans == 0) {
                    std::cout << i << " FFFF " << j << " " << n << std::endl;
                    std::cout << Dans << " " << Dmcans <<  " NO \n";
                    return 0;
                }
                // if (Scmans != Abmans || Scans != Amans) {
                end++;
                {   // end++;
                    // std::cout << i << " " << j << " " << n << std::endl;
                    //std::cout << Sans << " " << Scans << " " << Smans << " " << Scmans <<  " OK\n";

                    //std::cout << Aans << " " << Amans << " " << Abans << " " << Abmans << " " << Dbans << " NOT\n";

                    //  if (end == 1) return 0;
                }
            }
        }
        std::cout << "1000:OK\n" << std::endl;
    }

    return 0;
}
