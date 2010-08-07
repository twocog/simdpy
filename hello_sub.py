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
        print 'Got samples: ', str(len(samples))
    else:
        print 'No samples.'

