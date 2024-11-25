import time 
import random 

class StopandWait:
    def __init__(self,total_frames):
        self.current_frame = 0
        self.total_frames = total_frames
        self.timeout = 2
    
    def send_frames(self,frame_num):
        print(f"Frame {frame_num} sent.")
        time.sleep(1)

    def ack_receive(self,frame_num):
        ack = random.choice([True,False])
        return ack
    
    def main_function(self):

        while self.current_frame < self.total_frames:
            self.send_frames(self.current_frame)
            t = time.time()
            if t - time.time() < self.timeout:
                ack = self.ack_receive(self.current_frame)
                if ack:
                    print(f"Acknowledgement for frame {self.current_frame} received.")
                    self.current_frame = self.current_frame + 1
                else:
                    print(f"Retransmitting frame {self.current_frame} as No Acknowledgment.")
        print("All Acknowledgment Received.")

saw = StopandWait(total_frames=4)
saw.main_function()