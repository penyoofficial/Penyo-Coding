<script lang="ts">
import { ElRow, ElCol, ElStatistic, ElDivider, ElButton, ElText, ElScrollbar, ElTimeline, ElTimelineItem } from 'element-plus'
export default {
  name: "PokerPicker",
  data(): {
    ops: {
      value: string
      timestamp: string
    }[]
  } {
    return {
      ops: []
    }
  },
  components: {
    ElRow,
    ElCol,
    ElStatistic,
    ElDivider,
    ElButton,
    ElText,
    ElScrollbar,
    ElTimeline,
    ElTimelineItem
  },
  methods: {
    newOP() {
      this.ops.unshift({
        value: (() => {
          const rd = (upper: number) => { return Math.round((Math.random() * 100)) % upper }
          const suits = ["红桃", "黑桃", "梅花", "方块"]
          const power = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "小王", "大王"]
          const sp = [suits[rd(4)], power[rd(15)]]
          return `${sp[1] === "小王" || sp[1] === "大王" ? "" : sp[0]}${sp[1]}`
        })(),
        timestamp: (() => {
          const date = new Date()
          const hours = date.getHours().toString().padStart(2, '0')
          const minutes = date.getMinutes().toString().padStart(2, '0')
          const seconds = date.getSeconds().toString().padStart(2, '0')
          return `${hours}:${minutes}:${seconds}`
        })()
      })
    },
    getFrequency(v: string) {
      let num = 0
      this.ops.forEach(op => {
        if (op.value.includes(v))
          num++
      })
      return num ? num / this.ops.length : num
    },
    re(fn: Function, times: number) {
      while (times--)
        fn()
    }
  }
}
</script>

<template>
  <el-row>
    <el-col :span="4" v-for="i in ['红桃', '黑桃', '梅花', '方块']">
      <el-statistic :title="i + ' 频率'" :value="getFrequency(`${i}`)"
        :formatter="(num: number) => { return num.toFixed(4) }" />
    </el-col>
  </el-row>
  <el-divider />
  <el-row>
    <el-button type="primary" @click="newOP">抽一次</el-button>
    <el-button type="primary" @click="re(newOP, 10)">抽十次</el-button>
    <el-text type="primary" style="margin: 0 3em 0 1em;">样本总量：{{ ops.length }}</el-text>
    <el-button type="warning" @click="ops = []">清空</el-button>
  </el-row>
  <el-divider />
  <el-scrollbar height="266px">
    <el-timeline style="width: 50%; transform: translateX(0.5em);">
      <el-timeline-item v-for="op in ops" :timestamp="op.timestamp" :color="op === ops[0] ? '#0bbd87' : ''">
        {{ op.value }}
      </el-timeline-item>
    </el-timeline>
  </el-scrollbar>
</template>