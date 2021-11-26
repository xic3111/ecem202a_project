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
                        float votes[8] = { 0.0f };
                        votes[0] = dot(x,   0.052775857487  , 0.280264942089  , -0.660056446408  , 0.344240580657  , 0.974446746568  , 1.129884773967  , 0.030034528829  , 0.27732628217  , -0.698817870982  , -0.30266697256  , -0.062780796209  , 0.226906445807  , 0.007999346273  , 0.242140345627  , -0.703081392825  , 0.158111761038  , -0.430834587321  , 0.110451170108  , -0.015208361626  , 0.195446273556  , -0.690445603043  , 0.534467805195  , -0.553483887861  , -0.073553323262  , -0.03547106185  , 0.169587167658  , -0.670982669147  , 0.139374868279  , -0.157242443719  , -0.127313417698  , -0.048125630876  , 0.147809679534  , -0.6574122907  , -0.298972321689  , 0.246467249105  , -0.161821150275  , -0.058300619441  , 0.131445405463  , -0.649305641016  , -0.220977605142  , 0.209908416216  , -0.050551939525  , -0.068320061904  , 0.124785524367  , -0.644673436327  , -0.04432953047  , 0.070298098908  , 0.121268738138  , -0.074099578992  , 0.118414798837  , -0.64356689362  , 0.151992725131  , 0.117580489559  , 0.006262781854  , -0.070286731631  , 0.115993496328  , -0.642110751967  , 0.135559699931  , 0.187512205983  , 0.167806047607  , -0.069831944367  , 0.121976142708  , -0.642275153557  , -0.080991990258  , -0.107684152399  , -0.002815719744  , -0.078293824304  , 0.119251927033  , -0.648141494803  , 0.041755147368  , -0.498958515456  , -0.099560130071  , -0.083229226897  , 0.118636903979  , -0.653363867277  , 0.117981734657  , -0.291615399876  , -0.132558720179  , -0.084558659089  , 0.120459464057  , -0.658015419059  , -0.059709156479  , 0.00540965133  , -0.054372190477  , -0.087488946319  , 0.117584589956  , -0.662261683179  , 0.009952222164  , 0.202568647651  , 0.121960670604  , -0.090083658368  , 0.11285108118  , -0.664376936511  , -0.056781542611  , 0.229842946634  , 0.291565968922  , -0.090777519838  , 0.106857553474  , -0.667385249334  , -0.052057529301  , 0.189691176916  , 0.295413819024  , -0.090087567368  , 0.102980498918  , -0.667422079176  , -0.031053564958  , 0.118544625492  , 0.055156468989  , -0.091304468971  , 0.101202418301  , -0.666587930294  , -0.196656509459  , 0.006917712812  , -0.098675004718  , -0.096605773716  , 0.098066798029  , -0.667251630344  , -0.227258727269  , -0.19829536336  , -0.069697621777  , -0.093155461767  , 0.097541679362  , -0.668310329056  , -0.293349631989  , -0.046634963066  , 0.010106702643  , -0.091970521488  , 0.09677355211  , -0.668213287225  , -0.184982516674  , -0.107782215893  , 0.116044174837  , -0.092336655069  , 0.092287176831  , -0.66726337184  , 0.035348180857  , -0.063977528748  , 0.093898296061  , -0.090028488772  , 0.090485937019  , -0.66734258259  , -0.025786365825  , 0.081804871324  , 0.121799397495  , -0.085510277705  , 0.092106970092  , -0.668832055833  , -0.05717026724  , 0.106128333797  , 0.119510762302  , -0.085796822613  , 0.091769342707  , -0.672215037077  , 0.043953260943  , 0.010744392784  , 0.093696807263  , -0.083022807484  , 0.087296007708  , -0.671584179435  , 0.027807428527  , 0.070883593676  , -0.00749285942  , -0.085161883551  , 0.082812535853  , -0.668017422397  , -0.004170417336  , 0.082500641379  , 0.054413569438  , -0.082479803463  , 0.082227985981  , -0.667345062415  , 0.019522268147  , -0.085987253614  , 0.096005509108  , -0.085632648871  , 0.08386285514  , -0.668036969892  , 0.118924255417  , -0.245707415266  , -0.048815192704  , -0.087241166059  , 0.07988461629  , -0.666788817302  , 0.262143965661  , -0.201354244567  , 0.017203448842  , -0.090412184442  , 0.07752752337  , -0.66526113383  , 0.310893660898  , -0.161469299939  , 0.081362303646  , -0.091347687964  , 0.083601739085  , -0.663233085712  , 0.102679188165  , -0.095822928247  , -0.074159146387  , -0.090216626902  , 0.084824113856  , -0.664904059824  , -0.077966616794  , 0.032664831257  , -0.078643166372  , -0.085648038098  , 0.080895971777  , -0.668755974438  , -0.130992089136  , 0.178466395568  , -0.167649021363  , -0.083482500046  , 0.073792000568  , -0.672175419546  , -0.171480685526  , 0.204640519031  , -0.128369287715  , -0.080729862511  , 0.065600027565  , -0.679292223155  , -0.015804355408  , 0.215739972405  , 0.102607825921  , -0.073876124574  , 0.052669342919  , -0.699896734199  , 0.365505988264  , 0.140724649331  , 0.322396801395  , -0.084458696183  , 0.039264361791  , -0.71132505385  , -0.024483619901  , -0.291092672111  , 0.132299207489  , -0.086608210579  , 0.034717650493  , -0.708683532085  , -1.082157537836  , -0.019964685846  , 1.019284237729 );
                        votes[1] = dot(x,   0.101030755437  , -0.172557157165  , -0.206511272839  , 0.250263698825  , 0.675515563208  , 0.510951648362  , 0.091429419909  , -0.14318743842  , -0.191798988475  , -0.317884019062  , -0.056428863396  , 0.060417658753  , 0.081100443019  , -0.15158434057  , -0.17632099875  , 0.174961203265  , -0.237023807999  , 0.068617442552  , 0.072013159045  , -0.169131048067  , -0.162738373046  , 0.481013160866  , -0.309068141027  , -0.062977098567  , 0.06298934493  , -0.162191956977  , -0.156865297039  , -0.055770859063  , -0.07184954376  , -0.065940820057  , 0.060214374712  , -0.153378849945  , -0.149702473269  , -0.223784716458  , 0.099506801712  , -0.11388160725  , 0.055777977185  , -0.147571257269  , -0.141586803964  , -0.20314213097  , 0.037287113873  , -0.044107592027  , 0.053598118002  , -0.157192612096  , -0.128505609574  , 0.09174457374  , -0.028214678264  , 0.112877769478  , 0.05856794848  , -0.167614318265  , -0.11825331223  , 0.175120274919  , 0.017229901405  , -0.109479340659  , 0.066446545131  , -0.164704992115  , -0.113443949402  , -0.07065083421  , 0.053453965364  , 0.136904586849  , 0.07033341611  , -0.160249056064  , -0.115950039797  , -0.123662913753  , -0.235351011669  , 0.266100147769  , 0.072776207212  , -0.156808844284  , -0.1253566571  , 0.136474781874  , -0.279603620565  , 0.126687748873  , 0.082417141695  , -0.147455526727  , -0.131442788333  , 0.049703085057  , -0.048938768758  , 0.067144374931  , 0.092772578449  , -0.148675481098  , -0.137503385082  , -0.156783953957  , 0.066287386632  , -0.140809439529  , 0.097095271169  , -0.152514442034  , -0.135019904718  , -0.280067614137  , 0.064431332589  , -0.101375618332  , 0.106207617767  , -0.155510514325  , -0.135586090467  , 0.030940092427  , 0.195919490959  , 0.209799702581  , 0.116840718996  , -0.156936309153  , -0.136501987215  , 0.143859110713  , 0.258643900761  , 0.18068976621  , 0.119345733104  , -0.14770249672  , -0.135912848075  , -0.154221530447  , -0.032350476067  , 0.044053333648  , 0.127653262503  , -0.141706238154  , -0.13623083759  , -0.260740503145  , 0.004208227208  , -0.092348308055  , 0.134456388051  , -0.135812877105  , -0.129315749606  , -0.19716896308  , 0.00861382987  , -0.053940324023  , 0.138317116445  , -0.131579234595  , -0.121632705085  , -0.151307423005  , -0.019849060676  , -0.008721418121  , 0.146572627805  , -0.1310088322  , -0.115203426399  , 0.008007124658  , 0.007869746168  , 0.008777304523  , 0.147716097315  , -0.133067442578  , -0.111085617885  , 0.041077780532  , -0.054972558359  , 0.111801992278  , 0.158798704264  , -0.130756582101  , -0.117790174502  , 0.026379585329  , 0.026413176449  , 0.14372480969  , 0.168453421831  , -0.123158117758  , -0.126910241177  , 0.017691687135  , -0.032099401898  , 0.115333685961  , 0.172438978367  , -0.125727363648  , -0.133532411059  , -0.099415805084  , -0.065707739452  , 0.068270194402  , 0.175679394104  , -0.125176123228  , -0.137585625253  , -0.029132137382  , 0.056235859304  , -0.055338488071  , 0.17349637604  , -0.121666475122  , -0.14047614847  , 0.026603787102  , 0.063803738402  , -0.049592581645  , 0.183750702246  , -0.123889556107  , -0.146167174007  , 0.108338456988  , -0.02164893359  , 0.026338190554  , 0.185077050627  , -0.116678644914  , -0.1444110364  , 0.088571939233  , -0.205206707748  , 0.029934736214  , 0.185555448896  , -0.115292949432  , -0.137621256449  , 0.151843184167  , -0.157840837579  , 0.12356792947  , 0.18814193502  , -0.120712276089  , -0.126432011876  , 0.037354128078  , -0.115083552628  , 0.058486127026  , 0.182822815411  , -0.118199797842  , -0.112611000011  , -0.034273567589  , -0.079303119997  , -0.066692482096  , 0.184841359688  , -0.124534587377  , -0.104572012656  , -0.033229897738  , 0.010706706671  , 0.008265708099  , 0.189952603488  , -0.132305386341  , -0.10125268573  , 0.093718888872  , 0.088710236812  , -0.087241116445  , 0.197951314182  , -0.125546382578  , -0.106677994866  , -0.027240911572  , 0.215137281598  , -0.094236127584  , 0.200576924336  , -0.109854428214  , -0.108589434453  , -0.187543738044  , 0.145826131927  , -0.065424550133  , 0.206950789373  , -0.10594666016  , -0.116477305778  , 0.12698038641  , 0.152151776836  , 0.288023347571  , 0.210051859321  , -0.109281464358  , -0.119881575987  , 0.212593003468  , -0.265349779347  , 0.280857292116  , 0.222497827435  , -0.090520025933  , -0.119149274883  , -0.654781960669  , -0.016365437059  , 0.254366584916 );
                        votes[2] = dot(x,   -0.168182862198  , 0.290617741671  , 0.271437611985  , 0.041687382142  , 0.083963035354  , 0.273485994368  , -0.158164030273  , 0.259279375026  , 0.203390879028  , -0.081492476574  , 0.167887360707  , 0.128611502191  , -0.154141343176  , 0.22411614128  , 0.154343971623  , 0.007765495989  , 0.020333139598  , 0.015277452842  , -0.160881928043  , 0.177198430925  , 0.131404629714  , 0.128964842683  , -0.15466078932  , -0.061519294868  , -0.157481242208  , 0.140579502208  , 0.130897180964  , -0.069919687224  , 0.193562055888  , 0.00039305004  , -0.157996447114  , 0.119210376288  , 0.147225231339  , -0.16791234548  , 0.051474376961  , 0.060323887538  , -0.157428012535  , 0.099805750175  , 0.158072052764  , -0.036512603095  , 0.026237754099  , 0.05164157143  , -0.155951257935  , 0.083801767011  , 0.166033553379  , 0.057243047803  , -0.000531640806  , -0.000864779582  , -0.156572813872  , 0.083497353724  , 0.171092865994  , 0.059379523238  , -0.040332388642  , -0.107899666182  , -0.154023058287  , 0.086361584155  , 0.166659519713  , -0.031008499775  , 0.057419568977  , -0.001617642635  , -0.15462715898  , 0.099588888443  , 0.166288450228  , -0.052098960732  , -0.076500812135  , 0.165167234581  , -0.154113859457  , 0.099624750938  , 0.162896648259  , 0.048022005684  , -0.098203623028  , 0.173456078548  , -0.153359178996  , 0.094648637639  , 0.156380186301  , 0.088530278064  , -0.116800855891  , 0.191514518138  , -0.15940134362  , 0.097557916027  , 0.153479842012  , 0.033672552487  , -0.099689373672  , -0.084352726661  , -0.168942940687  , 0.091379954337  , 0.150383462732  , -0.054331045569  , 0.049100834782  , -0.305365205711  , -0.175522385841  , 0.079578944677  , 0.147042904002  , -0.046967315574  , 0.124150353594  , -0.041014808507  , -0.180169146719  , 0.073808512624  , 0.14867288979  , -0.148853374082  , 0.184703466776  , 0.124792455387  , -0.19247591504  , 0.064301393989  , 0.149973068363  , 0.04743423796  , 0.052843293843  , 0.042068631961  , -0.204811011947  , 0.061104048521  , 0.14998163005  , 0.134591171042  , -0.017669690168  , -0.011852514605  , -0.214552749013  , 0.061645151625  , 0.152436639371  , -0.039668832126  , -0.000509455019  , 0.072384251507  , -0.224295197899  , 0.058065820718  , 0.152583567981  , -0.033995052521  , 0.098723398273  , 0.038438922536  , -0.232942123076  , 0.059487218266  , 0.155913056237  , -0.119680713367  , 0.066729396242  , -0.055528718414  , -0.240320270016  , 0.060091023827  , 0.160025160637  , -0.004491755154  , 0.030863117943  , -0.119969707484  , -0.24325174567  , 0.058585176114  , 0.158042874697  , 0.146266676217  , 0.022114034516  , 0.002536886384  , -0.247986187422  , 0.055909569806  , 0.154947637951  , 0.130840215509  , -0.011739393668  , 0.149041035472  , -0.255818740634  , 0.047347192508  , 0.151485351207  , 0.088390599433  , -0.117686182747  , 0.085798288199  , -0.264319076032  , 0.040504889038  , 0.148899104374  , 0.046688299406  , -0.061312599522  , 0.1136446032  , -0.269714501538  , 0.029246150071  , 0.143198000034  , 0.059091875766  , -0.019727681078  , 0.038823968387  , -0.276835877486  , 0.022149480071  , 0.132612587247  , 0.131841260738  , -0.012904931202  , -0.067706313823  , -0.280726808213  , 0.019677825241  , 0.121906281513  , 0.070763366161  , -0.086615232894  , -0.037501064933  , -0.293192408781  , 0.014194770361  , 0.117288496924  , 0.059117079301  , -0.09253163388  , 0.039406456848  , -0.306257464783  , 0.001748483784  , 0.114974700225  , 0.131306076506  , 0.016240458156  , -0.056232776943  , -0.321004392418  , -0.013725584702  , 0.121598705769  , 0.072739020373  , 0.011249563917  , -0.036770754603  , -0.334277040524  , -0.02783305938  , 0.134867175872  , -0.00502537165  , -0.004208630231  , 0.147339556817  , -0.343410717964  , -0.039400135505  , 0.149042623332  , -0.063685409866  , 0.038974306886  , 0.191774826691  , -0.3525213877  , -0.050923621527  , 0.159566396004  , -0.019728786313  , 0.233209662623  , 0.128476343694  , -0.3590553385  , -0.057118247533  , 0.170709583255  , -0.076188271294  , 0.026891067742  , -0.201030074188  , -0.36549303205  , -0.078796834803  , 0.170573551374  , 0.356086852133  , 0.085001734236  , -0.150558360545  , -0.388316741315  , -0.106058307864  , 0.192745848364  , -0.135522929564  , -0.126812696225  , -0.307320675899  , -0.446489818455  , -0.116825061359  , 0.260191210761  , -0.285200076159  , 0.001267193862  , 0.731085529798 );
                        votes[3] = dot(x,   0.231373356889  , -0.060856198152  , 0.303497443582  , -0.022537422062  , -0.095842741292  , -0.177126695841  , 0.220003529183  , -0.041426761611  , 0.319292117737  , 0.14814258413  , -0.053258314971  , 0.030870998847  , 0.197103327313  , -0.024712622339  , 0.357104009799  , -0.24018897591  , 0.090972510994  , 0.023333302035  , 0.185823709592  , -0.016214368249  , 0.387475809549  , 0.034462628296  , 0.242935392898  , -0.039843334092  , 0.177634147347  , -0.00706749005  , 0.397023933134  , 0.096371690517  , 0.15713339062  , 0.014473905861  , 0.174221478245  , -0.004396557167  , 0.391141214777  , -0.056809228514  , -0.066268249875  , 0.079565031433  , 0.176465458719  , 0.003951099813  , 0.383577679073  , -0.053137996704  , -0.062578695337  , -0.017826242435  , 0.177348578689  , 0.004475484368  , 0.373501055909  , 0.131984805286  , 0.039232276408  , -0.104137789106  , 0.176883927926  , 0.001997358026  , 0.373249037689  , -0.034605438424  , -0.048960759663  , 0.02518980716  , 0.174385826818  , -0.00286984566  , 0.373137825  , -0.028084134715  , -0.110646694879  , -0.010379256428  , 0.174339080488  , -0.010081677768  , 0.363111839482  , 0.027001459652  , 0.141114873477  , 0.117660243965  , 0.181503638029  , -0.003148562406  , 0.345954862382  , -0.040529418811  , 0.053579739755  , 0.121251065736  , 0.189130845839  , 0.019802362718  , 0.337387033776  , -0.040738947263  , -0.007904103761  , 0.258371599223  , 0.196909459323  , 0.032894537931  , 0.335885293562  , 0.145391695401  , 0.005676722951  , -0.148433965495  , 0.19927746691  , 0.049007350178  , 0.33320216442  , -0.082254140128  , -0.23419269552  , -0.117612238551  , 0.206700490606  , 0.058008346701  , 0.343433926687  , -0.027827724883  , 0.211519597933  , -0.106302152326  , 0.216777317621  , 0.049065814181  , 0.353055775952  , -0.035965046067  , -0.029646857481  , 0.039190445578  , 0.220416606357  , 0.04283189352  , 0.361574220334  , 0.02857681436  , -0.051465984159  , -0.023273732745  , 0.229321810469  , 0.031934162338  , 0.3701609498  , 0.079230763583  , -0.046760563161  , 0.00350507882  , 0.246450498808  , 0.023566215995  , 0.373344932506  , 0.121804352697  , 0.023966131848  , 0.046091271837  , 0.24682628475  , 0.021987879604  , 0.388649251096  , -0.020602544699  , -0.032995482217  , 0.181321889504  , 0.252217961011  , 0.011269817638  , 0.401502331547  , -0.004328424086  , 0.144349068305  , -0.220931700796  , 0.252269700974  , 0.002723023678  , 0.404846185624  , 0.053182503785  , -0.061565718584  , -0.042693220343  , 0.271928990951  , -0.010208021613  , 0.393575374487  , -0.02481877817  , 0.085105940934  , 0.044143915133  , 0.270100830723  , -0.003415794318  , 0.383567951068  , 0.079138103572  , 0.027513146177  , -0.037677843094  , 0.271809315746  , 0.003003813004  , 0.368913016022  , 0.039490196044  , -0.038971393455  , 0.038833782897  , 0.286956165468  , 0.021330602625  , 0.358382761454  , -0.077007345438  , 0.023021667586  , 0.053408425601  , 0.285935817688  , 0.034112819088  , 0.354166220865  , 0.099449315127  , -0.141507620368  , 0.055603775199  , 0.284904799604  , 0.039463081692  , 0.368005838204  , 0.032840144664  , -0.009438333246  , -0.062121216508  , 0.28726605496  , 0.041520193457  , 0.393532457647  , -0.075340301522  , 0.116239983295  , 0.066648756758  , 0.289305038193  , 0.045981268125  , 0.41325614897  , -0.03195468271  , 0.007766456913  , 0.145358977332  , 0.294150938682  , 0.051597127648  , 0.430952010209  , -0.096588151272  , 0.009176985542  , -0.027675070274  , 0.289899397387  , 0.055343284963  , 0.434785448419  , -0.039235530221  , 0.066665805086  , 0.048137677049  , 0.285004403711  , 0.054593834637  , 0.427487950328  , 0.163648785073  , -0.036686528864  , -0.05618293744  , 0.287407627401  , 0.055086394293  , 0.4266762778  , 0.015619886406  , -0.087940634464  , 0.086430966525  , 0.292428146852  , 0.071278623411  , 0.407881388207  , -0.124118243426  , -0.020521793537  , 0.073202155692  , 0.300260934454  , 0.097022479493  , 0.405668272457  , -0.094556630576  , -0.083683324255  , -0.193260500565  , 0.307672212113  , 0.110925766535  , 0.328078573752  , 0.532836214362  , 0.054182932664  , -0.308345931733  , 0.315518423862  , 0.159403452412  , 0.285774915175  , -0.366171460086  , 0.178635793226  , 0.128732004667  , 0.375180185662  , 0.210002741101  , 0.252452234239  , 0.10614971941  , -0.254356086274  , 0.170884570812 );
                        votes[4] = dot(x,   -0.209778938565  , -0.60232087245  , 0.360541542447  , -0.538333067294  , -2.44073979925  , -0.439097797688  , -0.156352268245  , -0.630952269953  , 0.546395648965  , 0.738562680084  , 0.89167187864  , 0.271559716219  , -0.09438959207  , -0.556747172476  , 0.575071662144  , 0.285991750284  , 0.460930655459  , 0.102179280259  , -0.01900186869  , -0.399267262359  , 0.517599875214  , -1.622077889579  , 0.640228833028  , 0.18863488304  , 0.040683187657  , -0.336373891306  , 0.422788686937  , 0.045691407776  , -0.160557352766  , -0.091961945173  , 0.079823293613  , -0.309833109637  , 0.361921215615  , 0.903458472926  , -0.43153346869  , -0.352467970709  , 0.104343868674  , -0.277467232786  , 0.319776946809  , 0.209587782978  , -0.141113208236  , -0.26266333958  , 0.116388173379  , -0.229339083273  , 0.271168785121  , -0.026572670448  , 0.202065788634  , -0.113926327313  , 0.124336556466  , -0.187889574852  , 0.241959581152  , 0.138055295936  , 0.263094351608  , -0.071647331188  , 0.117783022464  , -0.169696644971  , 0.248656459529  , 0.032402535938  , -0.172525034631  , 0.006412552028  , 0.097190447991  , -0.177931180046  , 0.277564008323  , 0.192505808766  , -0.266043961799  , 0.144300178302  , 0.083183583912  , -0.169871238265  , 0.329360748471  , -0.191450523686  , 0.39666780062  , -0.138233164993  , 0.062097639668  , -0.185736218261  , 0.383626092554  , -0.206960622573  , 0.315891812836  , -0.145835096347  , 0.039334267943  , -0.207226044793  , 0.424028334218  , 0.046678130912  , -0.147449391464  , 0.563743048626  , 0.043322522033  , -0.20458042008  , 0.440972347539  , 0.145772799716  , -0.010139312281  , 0.580171586184  , 0.037233915203  , -0.19563816192  , 0.438965939005  , -0.445311460439  , -0.337420546459  , -0.2113980757  , 0.019529037534  , -0.176444382491  , 0.421866103749  , 0.171292880694  , -0.054441670206  , -0.455402480784  , 0.023296972864  , -0.173909316979  , 0.395808942366  , 0.244957699543  , -0.03116443502  , -0.031362975094  , 0.006328819042  , -0.168364603514  , 0.375365580898  , 0.01639820585  , -0.047699014277  , 0.372979328327  , -0.016774825569  , -0.163730857224  , 0.359331313712  , -0.015995775858  , 0.079857630782  , 0.166271979717  , -0.016193553686  , -0.169483803198  , 0.326898559133  , 0.315099619294  , 0.207990772366  , -0.237304873824  , -0.029490123458  , -0.162292275825  , 0.30178656141  , -0.119152216611  , -0.202654789484  , -0.232769978849  , -0.030348565292  , -0.162633646739  , 0.295254991332  , -0.071522603295  , 0.189921057998  , 0.227943983796  , -0.063472485603  , -0.171356564051  , 0.324851948487  , 0.116685701524  , -0.046437662389  , 0.085415248719  , -0.080856083937  , -0.189697280524  , 0.35944018738  , 0.116354749735  , -0.057117936683  , -0.347161820742  , -0.072018291276  , -0.184878368572  , 0.392597946297  , -0.17582321256  , 0.057938655229  , -0.031950399244  , -0.090612739622  , -0.197773790872  , 0.410583647434  , 0.230553389719  , -0.44177101685  , -0.264747189768  , -0.079470962825  , -0.194720587788  , 0.409581106293  , -0.011498273374  , 0.147729717134  , 0.362877828386  , -0.06705614945  , -0.181161162959  , 0.402668214233  , -0.234723662462  , 0.050652643004  , -0.077079556637  , -0.07256716654  , -0.189393932191  , 0.37707803585  , 0.216369050555  , -0.29300317412  , -0.206220408427  , -0.058706887103  , -0.181286941173  , 0.34447910708  , -0.02060537135  , -0.030138104017  , -0.236327475573  , -0.037926425496  , -0.163753981385  , 0.318320566529  , -0.102343750731  , 0.21461749225  , 0.248228471353  , -0.010023447452  , -0.154357038876  , 0.296291421991  , -0.322855894733  , -0.06460718127  , 0.2228967842  , 0.007158267676  , -0.136182774528  , 0.289717782867  , -0.148656437888  , 0.098993707319  , 0.315988139545  , 0.002686027833  , -0.124974895054  , 0.287809314  , 0.207779915682  , -0.35335718028  , -0.394484419312  , -0.020212964001  , -0.131908132176  , 0.339267645688  , 0.532089009013  , -0.326315990974  , -0.530084391123  , -0.065508221089  , -0.185657742678  , 0.367228771093  , 0.32703295339  , -0.526635526503  , -0.348100491827  , -0.053352694898  , -0.177183120575  , 0.538369796909  , -1.530834125305  , 0.055843061409  , -0.373249242398  , -0.016681268682  , -0.22694992317  , 0.544823274028  , 0.687540912163  , 1.099713145914  , 0.876053760757  , -0.071074541334  , -0.286551185884  , 0.486748462553  , 0.62940715978  , 0.365292272858  , 0.441530886285 );
                        votes[5] = dot(x,   0.118048027858  , 0.312723832146  , 0.389097928399  , 0.018478600838  , 0.061987936336  , -0.134930502702  , 0.120205540991  , 0.287046061367  , 0.333872011417  , 0.080069430747  , -0.22268033781  , 0.013135604215  , 0.10996235541  , 0.271038541149  , 0.318725348313  , -0.226652450502  , 0.222806306108  , -0.073016126175  , 0.102267920517  , 0.239507093401  , 0.330354583807  , 0.036436003051  , 0.162353132611  , -0.031274863915  , 0.08032205667  , 0.218726490205  , 0.373770200825  , 0.053633933386  , -0.059827865557  , -0.017184756053  , 0.066818312025  , 0.211266730597  , 0.395501069802  , -0.086505529165  , -0.084323593391  , 0.122881576335  , 0.06703428161  , 0.19981314497  , 0.413302578031  , 0.118815431752  , 0.079125787392  , 0.122045053246  , 0.068530464539  , 0.181157380246  , 0.437232471165  , -0.07391955059  , 0.029148757633  , -0.078453676577  , 0.054337257822  , 0.160301475543  , 0.454356004315  , -0.175014845531  , -0.188814816439  , 0.156590468122  , 0.054991131854  , 0.145166148176  , 0.4546908461  , 0.087059237244  , -0.028274527487  , -0.006796405334  , 0.062519982805  , 0.141935859413  , 0.444014166939  , -0.046615915492  , 0.088412315089  , -0.20237896873  , 0.06452059168  , 0.129035334383  , 0.437438833093  , -0.12156743875  , 0.080130384512  , -0.041817594159  , 0.069196156145  , 0.110250363299  , 0.430234577672  , 0.065590621811  , 0.057431696992  , -0.007278478362  , 0.073972703826  , 0.104821003288  , 0.423311396053  , 0.049546229452  , 0.115675598832  , 0.036624053598  , 0.068505996111  , 0.097724188164  , 0.418913803237  , 0.046094273196  , -0.083596904614  , -0.012028699332  , 0.073314181223  , 0.102227340835  , 0.415040863362  , 0.076786000592  , -0.097125900902  , -0.067291653407  , 0.076608239706  , 0.107910123987  , 0.41810545132  , -0.122082318364  , -0.149557350502  , -0.103941988505  , 0.07384393476  , 0.114225790361  , 0.424786153003  , 0.04705962407  , 0.009885457313  , -0.027721470166  , 0.079260140611  , 0.122667215026  , 0.431646116524  , 0.144611504522  , 0.029349569835  , -0.043488359166  , 0.09132610611  , 0.126488132608  , 0.435191307071  , 0.159840632386  , 0.041852253673  , 0.109507834911  , 0.091815580179  , 0.131905729473  , 0.448895528154  , -0.088546661662  , 0.007870733479  , 0.013841706401  , 0.092532618231  , 0.134548937598  , 0.460155864923  , 0.06816619453  , 0.07099055514  , 0.050726369989  , 0.096784018379  , 0.142666416979  , 0.456911302315  , -0.060304598179  , -0.013232818697  , -0.177031205612  , 0.10479172315  , 0.154953800938  , 0.443046969081  , 0.072762654984  , 0.008506475762  , -0.084315206611  , 0.117683747788  , 0.164658239944  , 0.425237788201  , -0.105253950607  , 0.004422516958  , 0.097645228275  , 0.114633136304  , 0.174140585793  , 0.418276622389  , -0.02117391379  , 0.005804750131  , -0.033852569692  , 0.12511389462  , 0.180803287225  , 0.410819831425  , 0.007806527407  , 0.095448722563  , 0.115479801739  , 0.129350050885  , 0.191706751903  , 0.409482442268  , -0.123053139932  , -0.135001406264  , -0.038349096289  , 0.121290914649  , 0.19713957629  , 0.407929856819  , 0.072727635404  , -0.068086581943  , -0.036972807632  , 0.130424613505  , 0.206233864809  , 0.409107179577  , -0.117073844943  , 0.271929003146  , 0.072674992845  , 0.12714416873  , 0.212375806584  , 0.4114304644  , -0.067929828763  , 0.100698157006  , 0.016500252193  , 0.126595006723  , 0.212011173886  , 0.40587209599  , -0.148508675079  , -0.106564533982  , -0.007107853361  , 0.127361928769  , 0.212837481598  , 0.402287176836  , -0.034658058503  , 0.117579881804  , 0.038274320323  , 0.126920222672  , 0.209426341491  , 0.401637277184  , 0.069950002653  , -0.056015856985  , -0.102749485416  , 0.129157680548  , 0.208454157448  , 0.388046191701  , -0.037626041865  , -0.042559314454  , 0.02216348806  , 0.149615466107  , 0.205527985434  , 0.358660628253  , 0.037084137784  , -0.07153053078  , 0.048465006233  , 0.165327235435  , 0.205385520485  , 0.321310062265  , 0.113743182217  , 0.061486824316  , -0.040598688853  , 0.142263912214  , 0.180002344402  , 0.326746968263  , -0.161093369078  , -0.227396990164  , -0.151213956547  , 0.18322018826  , 0.137160635583  , 0.351488885897  , 0.039292692139  , 0.197110373058  , -0.213692549841  , 0.229376166418  , 0.090616573049  , 0.333940455985  , 0.305322389285  , -0.333476938473  , 0.073040096578 );
                        votes[6] = dot(x,   -0.239014743743  , 0.025511874204  , 0.284628411612  , -0.09129705502  , 0.113329208759  , -0.195269190523  , -0.244465548745  , 0.049992084892  , 0.204800928031  , 0.007571876143  , -0.234277821364  , -0.289899633288  , -0.238898729595  , 0.051945098408  , 0.16839217741  , -0.083639597573  , 0.143575750804  , -0.106505188008  , -0.25196783672  , 0.034606993846  , 0.16154863156  , 0.113199112721  , 0.029129693352  , -0.000364826434  , -0.25955043648  , 0.036126579914  , 0.171420390673  , -0.170119059986  , -0.043020973845  , 0.000928552681  , -0.270481794603  , 0.045191484066  , 0.178517666533  , 0.01996028177  , -0.050658778833  , 0.136513657857  , -0.28296734532  , 0.049655210062  , 0.18520904337  , 0.143012142665  , 0.004104934885  , 0.121777341648  , -0.286125902309  , 0.052404056674  , 0.198407962402  , -0.137669845925  , -0.038759164637  , -0.023309224945  , -0.281351287206  , 0.044985189099  , 0.197710115988  , -0.13934612957  , -0.016989256619  , 0.18567764413  , -0.289419166725  , 0.044154815861  , 0.19604012589  , -0.018746748032  , -0.083735333366  , -0.063339197304  , -0.283432912811  , 0.041597027848  , 0.193756298046  , -0.005662191714  , 0.178438116576  , -0.251684872556  , -0.278809164818  , 0.037703695993  , 0.18425371308  , -0.024364017253  , 0.144298400627  , -0.088204611619  , -0.278203071137  , 0.044588965513  , 0.16204922207  , -0.068937448137  , 0.023204525059  , -0.074616821654  , -0.276424468139  , 0.057439207395  , 0.144195537912  , 0.027328107334  , -0.026236473953  , -0.031136482415  , -0.271937267152  , 0.060093595735  , 0.138081260987  , 0.135814428789  , 0.023666801492  , -0.00572868661  , -0.28046848356  , 0.067323270479  , 0.142608027761  , 0.122278979421  , -0.192881334814  , -0.02639367848  , -0.279322580176  , 0.063283132067  , 0.146240699149  , -0.117746451931  , -0.108380856395  , -0.069539024875  , -0.274019490418  , 0.061170468294  , 0.153445556264  , -0.058432735325  , 0.081070706992  , -0.036350668133  , -0.27064144964  , 0.057341425928  , 0.15639551301  , 0.164616518748  , -0.036175048015  , 0.005487201512  , -0.265870902727  , 0.056753365623  , 0.153957239719  , 0.101746159591  , -0.003139075639  , -0.100488680925  , -0.261786710991  , 0.062589108287  , 0.147532202649  , -0.013636213595  , -0.080823811097  , 0.005823124089  , -0.255704221565  , 0.063609948272  , 0.13504330789  , 0.100452615063  , 0.117889826068  , 0.126020221014  , -0.254967226124  , 0.069996469876  , 0.128372246444  , 0.035267227401  , -0.033412123014  , -0.150982308732  , -0.254746700854  , 0.079062823334  , 0.129188349499  , -0.171130938778  , -0.04980661312  , -0.087188309607  , -0.25194056567  , 0.075019225235  , 0.133628315924  , -0.012685876144  , -0.019171383366  , 0.068184451531  , -0.255533593741  , 0.067106463086  , 0.136047906507  , 0.047995039853  , 0.058777233025  , -0.13988089713  , -0.260121219798  , 0.066956144482  , 0.139541313776  , -0.210955967311  , 0.043930444015  , 0.150405806859  , -0.259776380496  , 0.053229381441  , 0.148208355412  , 0.040913715152  , -0.060205377796  , -0.276638345503  , -0.269854214901  , 0.040892233165  , 0.156153303442  , 0.003651669697  , 0.01301661978  , 0.011272833872  , -0.268204064532  , 0.027463939008  , 0.166909390677  , -0.132265463388  , 0.287005408496  , 0.078649793389  , -0.26926321968  , 0.012955503491  , 0.176323283573  , -0.171567647421  , 0.156063927592  , -0.030384701907  , -0.276654112451  , 0.015501083938  , 0.174746257179  , -0.034417613297  , -0.014085090119  , -0.100114535839  , -0.275403878485  , 0.013670244229  , 0.170617444056  , 0.111430534146  , 0.029811940279  , 0.010444911526  , -0.275860139647  , 0.020712548677  , 0.16386728726  , -0.083284650767  , -0.075054724826  , -0.243767080478  , -0.279230849917  , 0.030278689068  , 0.167251313623  , 0.042030305211  , 0.11019898575  , 0.113967214074  , -0.284151173876  , 0.028177671055  , 0.163834835548  , 0.123027766844  , -0.182859757501  , 0.111424065104  , -0.26936066109  , 0.039741411725  , 0.176398075134  , -0.12358179738  , 0.090368214629  , 0.116284988251  , -0.270602137752  , 0.05809636986  , 0.133967673088  , 0.034369078689  , -0.147129709709  , 0.200747437725  , -0.30559513325  , 0.114396091479  , 0.118045832128  , -0.259160599414  , -0.089183619135  , -0.136896474488  , -0.308394943495  , 0.15742172553  , 0.13496644019  , 0.577358400839  , -0.158203386204  , -0.848972750009 );
                        votes[7] = dot(x,   0.113748546834  , -0.073384162343  , -0.742635218776  , -0.002502718086  , 0.627340050319  , -0.967898229943  , 0.097308828351  , -0.058077333471  , -0.717134725722  , -0.272303102908  , -0.430133105597  , -0.441602292745  , 0.091264192826  , -0.056195991079  , -0.694234777714  , -0.076349186591  , -0.270759967644  , -0.140337333612  , 0.086955205925  , -0.062146113054  , -0.675199553755  , 0.293534336766  , -0.05743423368  , 0.080897858097  , 0.090874003934  , -0.059386401652  , -0.668052426348  , -0.039262293685  , 0.14180273314  , 0.286605430399  , 0.095526413999  , -0.055869753734  , -0.667191634097  , -0.089434613391  , 0.235335663012  , 0.228886575071  , 0.095074391109  , -0.059632120427  , -0.669045855067  , 0.042354978515  , -0.152972102891  , 0.079685147243  , 0.09453188754  , -0.060092517297  , -0.673164782075  , 0.001519170604  , -0.273239437875  , 0.086545289908  , 0.097897989376  , -0.053692282112  , -0.676547399287  , -0.175581405698  , -0.102807521209  , -0.084694363237  , 0.100122430376  , -0.054404561775  , -0.683630074863  , -0.106531256382  , 0.096795850039  , -0.228990684783  , 0.103509088764  , -0.056836004534  , -0.686509569665  , 0.089524703531  , 0.27761463286  , -0.236348243586  , 0.109232827745  , -0.055787063392  , -0.686406653382  , 0.151659463574  , 0.202089433537  , -0.053579392315  , 0.111949693684  , -0.05473548816  , -0.684870456763  , -0.005168701615  , 0.068731093399  , -0.15674137575  , 0.117395461306  , -0.057270602808  , -0.685381599616  , -0.086123605151  , 0.080325879345  , -0.141262297647  , 0.120167897937  , -0.058694816257  , -0.684271451019  , 0.079019075969  , -0.011838704098  , -0.160021808252  , 0.122618322969  , -0.068840307627  , -0.687128633839  , 0.346882971067  , -0.134004606945  , -0.048965303083  , 0.120513932875  , -0.067544444688  , -0.684053683413  , 0.161552728337  , -0.291011809869  , -0.011202992036  , 0.119679725741  , -0.063898231385  , -0.682253013079  , -0.124320545203  , -0.147363188395  , -0.022569588461  , 0.124192897932  , -0.064178428447  , -0.680731022398  , -0.082051151142  , 0.107828805766  , -0.135607422116  , 0.121571258055  , -0.066975929551  , -0.677694052429  , 0.096701153658  , 0.047654047845  , -0.170128711246  , 0.118471942968  , -0.071027179652  , -0.674616074872  , 0.286337908177  , -0.134281587061  , -0.003506053228  , 0.11878378254  , -0.072388365859  , -0.670984408383  , 0.251517936487  , -0.097391586545  , 0.207662327696  , 0.121202899833  , -0.072063021874  , -0.667060896626  , -0.028556735947  , 0.00637657146  , 0.057032170036  , 0.115980002534  , -0.07076656964  , -0.66357275916  , -0.140358535281  , -0.127700223477  , -0.226116741205  , 0.110055114393  , -0.071422812477  , -0.661079583516  , -0.168914661961  , -0.017935881317  , -0.164875499704  , 0.110286017846  , -0.072761664879  , -0.661573394287  , 0.07658383516  , 0.089100284485  , -0.080915206697  , 0.110326388744  , -0.073941016977  , -0.659056853775  , 0.004239805072  , 0.213563329227  , -0.10536010014  , 0.105341483797  , -0.074720575446  , -0.656142554005  , -0.087336862505  , 0.062407988591  , -0.147139117973  , 0.1062796288  , -0.076821638134  , -0.653857563524  , -0.134197773176  , 0.13439677081  , 0.110263361067  , 0.104362969063  , -0.072686100548  , -0.656085338973  , -0.169949001512  , 0.155358135091  , 0.044628386858  , 0.106399025803  , -0.068812074246  , -0.658367427197  , -0.181046698885  , 0.217336278533  , -0.075324887205  , 0.102362306748  , -0.073919135153  , -0.653172484425  , -0.097695675103  , 0.15716754072  , -0.196946665608  , 0.097695264751  , -0.079170328456  , -0.649736111348  , 0.144174308363  , 0.014426038427  , -0.142131310011  , 0.096429553326  , -0.081006417376  , -0.648101401032  , 0.114564187111  , 0.029600495658  , 0.009749265245  , 0.09908566671  , -0.078034795686  , -0.648817060287  , -0.126845455306  , 0.067507204181  , 0.23503806177  , 0.100373098481  , -0.070398144186  , -0.650357479288  , -0.349632286805  , -0.05175939046  , 0.391122235699  , 0.108488988966  , -0.055119020844  , -0.653433106596  , 0.056898657095  , 0.070006639739  , 0.629521491394  , 0.106437075576  , -0.039767208179  , -0.68136252341  , 0.276148974524  , -0.113377454604  , 0.172199904531  , 0.086261367987  , -0.007934845873  , -0.661672125754  , -0.154087998806  , -0.70302054538  , -0.760032564802  , 0.085513334349  , 0.001137583003  , -0.640465996761  , 0.40390190535  , 0.415807067135  , -1.84121915611 );
                        // return argmax of votes
                        uint8_t classIdx = 0;
                        float maxVotes = votes[0];

                        for (uint8_t i = 1; i < 8; i++) {
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