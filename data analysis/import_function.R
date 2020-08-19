library(psych)
readin<-function(x, y){
#create loop where pack number and cell number are dynamic
temp<-read.csv(paste0(x,"-",y,".TXT"))
temp<-temp[(max(which((is.na(as.numeric(as.character(temp[,4]))))))+2):nrow(temp),1:4]
temp$State<-as.numeric(as.character(temp$State)) #0 is discharge
temp$Times<-as.numeric(as.character(temp$Times))
temp$V<-as.numeric(as.character(temp$V))
names(temp)[4] <- "I"
temp$I<-as.numeric(as.character(temp$I))
temp$I[temp$I < 0.01] <- 0
temp$Ah<-temp$I/360

tempdischarge<-as.data.frame(tapply( temp$Ah[temp$State == 0], temp$Times[temp$State == 0], sum))
#remove first and last cycles due to partial data
tempdischarge<-as.data.frame(tempdischarge[2:(nrow(tempdischarge)-1),])
names(tempdischarge)[1]<- "Ah"

plot(tapply( temp$Ah[temp$State == 0], temp$Times[temp$State == 0], sum), type = "l", ylim = range(0:2.2))
return(describe(tempdischarge))
#return(tempdischarge)
assign(paste0(x,".",y), tempdischarge, envir = .GlobalEnv )
}


readin(1,1) #bounces back when it got warmer, downwards was cold related
readin(1,7) #stable
readin(2,1) #stable
readin(2,3) #down
readin(3,1) #stable
readin(5,3) #stable
readin(5,4) #stable
readin(6,1) #stable
readin(6,6) #stable
readin(7,5) #stable
readin(7,6) #stable
#readin(1,6)
#readin(1,8)
#readin(2,4)
#readin(2,5)
#readin(2,8)
#readin(3,8)
#readin(4,5)
#readin(4,6)
#readin(4,8)
#readin(5,1)
#readin(5,6)
#readin(5,7)
#readin(6,3)
#readin(6,4)
#readin(6,7)
#readin(6,8)
#readin(7,1)
#readin(7,3)
#readin(7,4)
#readin(7,7)
#readin(7,8)
#readin(8,1)
#readin(8,2)
#readin(8,3)
#readin(8,4)
#readin(8,5)
#readin(8,6)
#readin(8,7)
#readin(8,8)