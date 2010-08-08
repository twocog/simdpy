import simdpy
import time

rt = simdpy.DDSRuntime('')
tqos = simdpy.DDSTopicQos()
tqos.set_reliable()
tqos.set_transient()

hello_topic = simdpy.HelloTopic( "helloTopic", tqos )

dwqos = simdpy.DDSWriterQos(tqos)

hello_writer = simdpy.HelloWriter( hello_topic, dwqos )

hello_sample = simdpy.create_hello('')

for i in range(100):
    hello_sample.name.set( 'aloha : ' + str(i) )
    hello_writer.write( hello_sample )
    time.sleep(1)

