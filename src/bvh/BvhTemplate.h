#pragma once

#define STRINGIFY(x) #x

static string bvh_header_template = STRINGIFY(
HIERARCHY
ROOT Hips
{
    OFFSET 0.000 95.729 0.000
    CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
    JOINT RightUpLeg
    {
        OFFSET -9.625 -1.639 0.000
        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
        JOINT RightLeg
        {
            OFFSET 0.000 -41.481 0.000
            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
            JOINT RightFoot
            {
                OFFSET 0.000 -43.120 0.000
                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                End Site
                {
                    OFFSET 0.000 -7.850 17.850
                }
            }
        }
    }
    JOINT LeftUpLeg
    {
        OFFSET 9.625 -1.639 0.000
        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
        JOINT LeftLeg
        {
            OFFSET 0.000 -43.120 0.000
            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
            JOINT LeftFoot
            {
                OFFSET 0.000 -43.120 0.000
                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                End Site
                {
                    OFFSET 0.000 -7.850 17.850
                }
            }
        }
    }
    JOINT Spine
    {
        OFFSET 0.000 16.395 0.000
        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
        JOINT Spine1
        {
            OFFSET 0.000 10.023 0.000
            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
            JOINT Spine2
            {
                OFFSET 0.000 10.437 0.000
                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                JOINT Spine3
                {
                    OFFSET 0.000 10.023 0.000
                    CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                    JOINT Neck
                    {
                        OFFSET 0.000 10.713 0.000
                        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                        JOINT Head
                        {
                            OFFSET 0.000 9.720 0.000
                            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                            End Site
                            {
                                OFFSET 0.000 16.450 0.000
                            }
                        }
                    }
                    JOINT RightShoulder
                    {
                        OFFSET -3.275 7.142 0.000
                        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                        JOINT RightArm
                        {
                            OFFSET -13.100 0.000 0.000
                            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                            JOINT RightForeArm
                            {
                                OFFSET -27.250 0.000 0.000
                                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                JOINT RightHand
                                {
                                    OFFSET -26.750 0.000 0.000
                                    CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                    JOINT RightHandThumb1
                                    {
                                        OFFSET -2.560 0.196 3.210
                                        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                        JOINT RightHandThumb2
                                        {
                                            OFFSET -3.788 0.000 0.000
                                            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                            JOINT RightHandThumb3
                                            {
                                                OFFSET -2.631 0.000 0.000
                                                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                End Site
                                                {
                                                    OFFSET -2.256 0.000 0.000
                                                }
                                            }
                                        }
                                    }
                                    JOINT RightInHandIndex
                                    {
                                        OFFSET -3.316 0.523 2.035
                                        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                        JOINT RightHandIndex1
                                        {
                                            OFFSET -5.366 -0.094 1.028
                                            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                            JOINT RightHandIndex2
                                            {
                                                OFFSET -3.723 0.000 0.000
                                                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                JOINT RightHandIndex3
                                                {
                                                    OFFSET -2.111 0.000 0.000
                                                    CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                    End Site
                                                    {
                                                        OFFSET -1.857 0.000 0.000
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    JOINT RightInHandMiddle
                                    {
                                        OFFSET -3.479 0.532 0.778
                                        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                        JOINT RightHandMiddle1
                                        {
                                            OFFSET -5.322 -0.086 0.323
                                            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                            JOINT RightHandMiddle2
                                            {
                                                OFFSET -4.062 0.000 0.000
                                                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                JOINT RightHandMiddle3
                                                {
                                                    OFFSET -2.547 0.000 0.000
                                                    CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                    End Site
                                                    {
                                                        OFFSET -2.031 0.000 0.000
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    JOINT RightInHandRing
                                    {
                                        OFFSET -3.461 0.553 -0.133
                                        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                        JOINT RightHandRing1
                                        {
                                            OFFSET -4.767 -0.023 -0.493
                                            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                            JOINT RightHandRing2
                                            {
                                                OFFSET -3.541 0.000 0.000
                                                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                JOINT RightHandRing3
                                                {
                                                    OFFSET -2.456 0.000 0.000
                                                    CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                    End Site
                                                    {
                                                        OFFSET -1.910 0.000 0.000
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    JOINT RightInHandPinky
                                    {
                                        OFFSET -3.251 0.483 -1.236
                                        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                        JOINT RightHandPinky1
                                        {
                                            OFFSET -4.259 -0.023 -1.122
                                            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                            JOINT RightHandPinky2
                                            {
                                                OFFSET -2.835 0.000 0.000
                                                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                JOINT RightHandPinky3
                                                {
                                                    OFFSET -1.792 0.000 0.000
                                                    CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                    End Site
                                                    {
                                                        OFFSET -1.692 0.000 0.000
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    JOINT LeftShoulder
                    {
                        OFFSET 3.275 7.142 0.000
                        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                        JOINT LeftArm
                        {
                            OFFSET 13.100 0.000 0.000
                            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                            JOINT LeftForeArm
                            {
                                OFFSET 27.250 0.000 0.000
                                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                JOINT LeftHand
                                {
                                    OFFSET 26.750 0.000 0.000
                                    CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                    JOINT LeftHandThumb1
                                    {
                                        OFFSET 2.560 0.196 3.210
                                        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                        JOINT LeftHandThumb2
                                        {
                                            OFFSET 3.788 0.000 0.000
                                            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                            JOINT LeftHandThumb3
                                            {
                                                OFFSET 2.631 0.000 0.000
                                                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                End Site
                                                {
                                                    OFFSET 2.256 0.000 0.000
                                                }
                                            }
                                        }
                                    }
                                    JOINT LeftInHandIndex
                                    {
                                        OFFSET 3.316 0.523 2.035
                                        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                        JOINT LeftHandIndex1
                                        {
                                            OFFSET 5.366 -0.094 1.028
                                            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                            JOINT LeftHandIndex2
                                            {
                                                OFFSET 3.723 0.000 0.000
                                                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                JOINT LeftHandIndex3
                                                {
                                                    OFFSET 2.111 0.000 0.000
                                                    CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                    End Site
                                                    {
                                                        OFFSET 1.857 0.000 0.000
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    JOINT LeftInHandMiddle
                                    {
                                        OFFSET 3.479 0.532 0.778
                                        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                        JOINT LeftHandMiddle1
                                        {
                                            OFFSET 5.322 -0.086 0.323
                                            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                            JOINT LeftHandMiddle2
                                            {
                                                OFFSET 4.062 0.000 0.000
                                                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                JOINT LeftHandMiddle3
                                                {
                                                    OFFSET 2.547 0.000 0.000
                                                    CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                    End Site
                                                    {
                                                        OFFSET 2.031 0.000 0.000
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    JOINT LeftInHandRing
                                    {
                                        OFFSET 3.461 0.553 -0.133
                                        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                        JOINT LeftHandRing1
                                        {
                                            OFFSET 4.767 -0.023 -0.493
                                            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                            JOINT LeftHandRing2
                                            {
                                                OFFSET 3.541 0.000 0.000
                                                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                JOINT LeftHandRing3
                                                {
                                                    OFFSET 2.456 0.000 0.000
                                                    CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                    End Site
                                                    {
                                                        OFFSET 1.910 0.000 0.000
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    JOINT LeftInHandPinky
                                    {
                                        OFFSET 3.251 0.483 -1.236
                                        CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                        JOINT LeftHandPinky1
                                        {
                                            OFFSET 4.259 -0.023 -1.122
                                            CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                            JOINT LeftHandPinky2
                                            {
                                                OFFSET 2.835 0.000 0.000
                                                CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                JOINT LeftHandPinky3
                                                {
                                                    OFFSET 1.792 0.000 0.000
                                                    CHANNELS 6 Xposition Yposition Zposition Yrotation Xrotation Zrotation
                                                    End Site
                                                    {
                                                        OFFSET 1.692 0.000 0.000
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
MOTION
);