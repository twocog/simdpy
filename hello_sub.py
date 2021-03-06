import simdpy
import time

rt = simdpy.DDSRuntime('')
tqos = simdpy.DDSTopicQos()
tqos.set_reliable()
tqos.set_transient()

hello_topic = simdpy.HelloTopic( "helloTopic", tqos )

drqos = simdpy.DDSReaderQos(tqos)

hello_reader = simdpy.HelloReader( hello_topic, drqos )

samples = simdpy.HelloSeq()
infos = simdpy.SampleInfoSeq()

while 1:
    hello_reader.read( samples, infos )
    time.sleep(1)
    if samples.length() > 0:
        print 'Got samples: ', str(samples.length())
        for i in range(samples.length()):
            print 'Sample %s: %s' % (i, str(samples.get(i).name))
    else:
        print 'No samples.'
    hello_reader.return_loan( samples, infos )

