import java.util.*;

public class ServerFreeTime {

    static class JobCommand implements Comparable<JobCommand>{
        int time = 0;
        boolean command;
        public JobCommand(String timeString, boolean command) {
            String[] split = timeString.split(":");
            time += Integer.parseInt(split[0]) * 3600;
            time += Integer.parseInt(split[1]) * 60;
            time += Integer.parseInt(split[2]);
            this.command = command;
        }
        @Override
        public int compareTo(JobCommand that) {
            return this.time - that.time;
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        JobCommand[] jobCommands = new JobCommand[2 * N];
        for (int n = 0; n < 2 * N; n += 2) {
            String startString = in.next();
            String endString = in.next();
            jobCommands[n] = new JobCommand(startString, true);
            jobCommands[n + 1] = new JobCommand(endString, false);
        }
        Arrays.sort(jobCommands);
        int jobsActive = 1;
        int idleTime = jobCommands[0].time;
        for (int n = 1; n < 2 * N; n++) {
            idleTime += jobsActive == 0 ? jobCommands[n].time - jobCommands[n - 1].time : 0;
            jobsActive += jobCommands[n].command ? 1 : -1;
        }
        idleTime += (60 * 60 * 24) - jobCommands[(2 * N) - 1].time;
        System.out.println(idleTime);
    }
}
