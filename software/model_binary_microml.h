#pragma once
#include <cstdarg>
namespace Eloquent {
    namespace ML {
        namespace Port {
            class LogisticRegression {
                public:
                    /**
                    * Predict class for features vector
                    */
                    int predict(float *x) {
                        float votes[2] = { 0.0f };
                        votes[0] = dot(x,   -0.841526666558  , -1.925873314828  , 0.909694037231  , -0.285150771423  , -1.351242311893  , -0.087055528863  , -0.656596483828  , -1.913419935739  , 1.767006856413  , 0.143587645789  , 0.620104830207  , 0.14767514833  , -0.359578455889  , -1.666191308792  , 1.668486452384  , 0.66713095349  , 0.035263349276  , 0.00795593013  , 0.067977605945  , -1.077883448455  , 1.144817499207  , -1.149258717695  , 0.361056757072  , 0.212976460766  , 0.343945189887  , -0.763532562851  , 0.453100764053  , -0.074939205396  , -0.277168010317  , -0.075761432834  , 0.576543486825  , -0.538965515918  , -0.037028370313  , 0.809039978787  , -0.132019727982  , -0.387907738509  , 0.681600416298  , -0.308217792464  , -0.439992679805  , -0.253728482338  , 0.15795806203  , -0.205745455218  , 0.751334498313  , 0.006218779737  , -0.755510780901  , 0.034379686815  , -0.168308361699  , 0.068056766405  , 0.782024128818  , 0.274632462238  , -0.92723768631  , 0.216591869952  , 0.311576610879  , -0.072868161923  , 0.729695154329  , 0.387003052896  , -0.855446299273  , -0.091528220919  , -0.176879797412  , 0.005436001491  , 0.63826840566  , 0.297677562847  , -0.660510094416  , 0.180586430111  , -0.126667595271  , 0.117748308605  , 0.544717663351  , 0.296903241949  , -0.395847528033  , -0.028284129915  , -0.021956270688  , 0.020675354165  , 0.450658375072  , 0.229457028856  , -0.171467734499  , -0.150057696833  , 0.154882040477  , -0.20202999903  , 0.327354883194  , 0.139040787832  , -0.013050218473  , -0.03332119071  , -0.157009514258  , 0.170982081347  , 0.290203662101  , 0.092501185728  , 0.036254655525  , 0.215640946417  , 0.177992438517  , 0.315365989629  , 0.266093378467  , 0.073629964436  , -0.012296657447  , -0.386165615454  , -0.208959086448  , -0.17789711215  , 0.186246726194  , 0.178855707082  , -0.085953912131  , 0.264308631924  , 0.13044883622  , -0.26497589757  , 0.152613132932  , 0.179020645323  , -0.163625901863  , -0.172971264407  , -0.067544453932  , 0.265003353602  , 0.008470508292  , 0.148440355915  , -0.271850303287  , 0.175893018008  , -0.036247108868  , -0.075799880801  , -0.173203921718  , 0.162783298687  , -0.362448514886  , -0.355770578251  , -0.018207478099  , 0.070777363854  , -0.218870452045  , 0.139587982718  , -0.503881521401  , 0.459691921209  , 0.117039738197  , -0.029436691853  , -0.280547168367  , 0.15006702795  , -0.621474692285  , -0.342915730881  , -0.164351335121  , 0.092946302494  , -0.366197689654  , 0.132496084052  , -0.617334824577  , 0.077805760866  , 0.259243629121  , -0.059293811022  , -0.590626505679  , 0.087218450469  , -0.466232925989  , -0.028616311963  , -0.226077561199  , 0.178023615323  , -0.624504503908  , -0.01587189441  , -0.322574473228  , 0.106930043902  , 0.051098852562  , -0.203997234004  , -0.62277040291  , 0.026883310257  , -0.165879139085  , -0.143711113705  , -0.001625983945  , 0.114851402902  , -0.701153782618  , 0.030533567935  , -0.030103428738  , 0.143229103575  , -0.193203758719  , -0.214274406221  , -0.717623750081  , 0.011672446229  , 0.021196992437  , -0.028208093977  , 0.066137891082  , 0.075924543514  , -0.703853505573  , 0.023535069443  , 0.023887238314  , -0.057906212588  , -0.046132468142  , -0.05698250654  , -0.726899030247  , -0.004479915772  , -0.060200710576  , 0.111528850297  , -0.036473142943  , 0.02716043261  , -0.627200173578  , 0.020821815453  , -0.179146988536  , -0.093749510496  , -0.122977317042  , -0.120778494438  , -0.625044126554  , 0.13682970251  , -0.293258632648  , 0.078830286498  , 0.162342858814  , 0.109115313288  , -0.400076160713  , 0.242361020327  , -0.393169461481  , -0.076473931676  , -0.125184565015  , -0.117228437907  , -0.258107641651  , 0.440747887911  , -0.543330629946  , -0.105428202879  , -0.013481528363  , 0.211353970149  , -0.304801019166  , 0.567970290058  , -0.625705064419  , 0.17976173519  , -0.055208502118  , -0.198473711564  , -0.439838106416  , 0.476476649968  , -0.248110575433  , 0.106474669756  , -0.185725400194  , -0.289007327549  , -0.699854312994  , 0.182446031504  , 0.164695480706  , 0.323384017247  , -0.184776806027  , 0.104955489185  , -0.592307605463  , 0.141110587706  , 1.146459160917  , -1.138340275698  , -0.032268589869  , -0.152631137273  , -0.734456597246  , -0.109804214268  , 1.505421002095  , 0.721543642638  , 0.525401864821  , 0.339807376811  , -1.062941945516  , -0.343338441401  , 1.4830608692  , 0.144053422841  , 0.429163017159  , 0.175719215306 );
                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 2; i++) {
                            if (votes[i] > maxVotes) {
                                classIdx = i;
                                maxVotes = votes[i];
                            }
                        }

                        return classIdx;
                    }

                protected:
                    /**
                    * Compute dot product
                    */
                    float dot(float *x, ...) {
                        va_list w;
                        va_start(w, 240);
                        float dot = 0.0;

                        for (uint16_t i = 0; i < 240; i++) {
                            const float wi = va_arg(w, double);
                            dot += x[i] * wi;
                        }

                        return dot;
                    }
                };
            }
        }
    }